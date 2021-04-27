//#include "exam.h"

/***
 * -------------------------------------------------------------------------------------------------------------------
 * 题目
 * -------------------------------------------------------------------------------------------------------------------
 *
 * 编写一个程序，从命令行读取一个软件包的名称，调用“dpkg -L”命令获得该软件包的文件列表，并检查所有文件。
 * 要求：
 * 1. 使用cmake和c++开发
 * 2. 可执行文件名称和位置是./src/pkgverify
 * 3. 检查该软件包所有文件，确认：
 *   - 路径存在
 *   - 文件存在
 *   - 如果是符号链接，链接的文件也存在
 *   - /usr路径下的文件，确认文件属主都是root
 * 4. 输出所有有问题的文件或路径名
 *
 * 示例：
 * 如果/etc/cups路径被删除了，则运行结果如下：
 * pkgverify cups
 * /etc/cups
 * /etc/cups/snmp.conf
 *
 */

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>
#include <QProcess>

#include <iostream>

static QStringList errorList;

QFileInfo getSymLink(QFileInfo file)
{
    QFileInfo symLink(file.symLinkTarget());
    if (symLink.isSymLink())
        return getSymLink(symLink);

    return symLink;
}

void dpkgPackage(const QString &package)
{
    QString cmd = QString("dpkg -L %1").arg(package);
    QProcess process;
    process.start(cmd);
    process.waitForFinished(-1);

    int exitCode = process.exitCode();
    QProcess::ExitStatus status = process.exitStatus();

    if (0 != exitCode || QProcess::ExitStatus::NormalExit != status)
        return;

    while (!process.atEnd()) {
        QString file = process.readLine().trimmed();
        QFileInfo fileInfo(file);

        // usr 目录下的要校验属主为 root
        if (fileInfo.absolutePath().left(4) == QString("/usr")) {
            if (fileInfo.isFile()) {
                if (0 != fileInfo.ownerId()) {
                    std::cout << file.toStdString() << std::endl;
                    errorList.append(file);
                }
            }
        }

        // 如果是链接文件，找出实际文件，判断该文件是否存在
        if (fileInfo.isSymLink()) {
            QFileInfo sourceFile = getSymLink(fileInfo);
            if (!sourceFile.exists()) {
                std::cout << file.toStdString() << std::endl;
                errorList.append(fileInfo.symLinkTarget());
            }
        }

        if (!fileInfo.exists()) {
            std::cout << file.toStdString() << std::endl;
            errorList.append(file);
        }
    }

    process.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.setApplicationName("pkgverify");
    a.setApplicationVersion("1.0.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("pkgverify tools");
    parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsCompactedShortOptions);
    parser.addHelpOption();
    parser.addVersionOption();
    parser.process(a);

    if (2 == argc) {
        dpkgPackage(QString::fromLatin1(argv[1]));
    } else {
        parser.showHelp(1);
    }

    return 0;
}

