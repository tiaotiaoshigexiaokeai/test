//#include "exam.h"

/**
 *
 * -------------------------------------------------------------------------------------------------------------------
 * 题目
 * -------------------------------------------------------------------------------------------------------------------
 *
 * 遵循 https://specifications.freedesktop.org/desktop-entry-spec/latest/ 标准实现一个desktop文件解析工具
 *
 * 功能要求
 * - desktop文件格式无错误时进程退出码为0
 * - 实现对desktop文件Name(程序名称)、Exec(可执行文件)、Icon(图标文件)三个字段的解析
 * - 需要检测文件的格式，遇到错误时以退出码 1 退出进程
 * - 输入接收一个desktop文件的绝对路径，能够输出程序名称、图标文件（图标文件不考虑从系统图标主题中查找）
 * - 能够在指定一个desktop文件后启动进程，且允许为其指定参数
 *
 * 其它要求
 * - 使用cmake构建工程
 * - 可执行文件位置和名称为：./src/freedesktop
 *
 * 示例
 * - a.desktop文件内容为:
 *     [Desktop Entry]
 *     Name=A;
 *     Name[zh_CN]="我是A";
 *     Exec=cat %f
 *     Icon=/tmp/a.png
 *
 * - 输入参数（-d指定desktop文件的绝对路径，-n表示要获取应用程序名称）：
 *     freedesktop -d /home/a/a.desktop -n
 * - 输出结果：
 *     A或我是A（中文环境下，注意应该去掉引号）
 *
 * - 输入参数（-i表示要获取应用程序的图标）
 *     freedesktop -d /home/a/a.desktop -i
 * - 输出结果（如图标数据不是一个文件路径，则先将图标文件保存为文件后再返回此文件的绝对路径）：
 *     /tmp/a.png
 *
 * - 输入参数（-e表示要启动此应用程序，其后可根一个或多个传入参数）
 *     freedesktop -d /home/a/a.desktop -e /home/a/test.txt
 * - 输出结果：
 *     输出结果为 /home/a/test.txt 文件的内容，也就是Exec命令执行时对标准输出通道所写入的全部数据
 *
 */

#include <QApplication>
#include <QCommandLineParser>
#include <QSettings>
#include <QTextCodec>
#include <QDebug>
#include <QFile>
#include <QProcess>
#include <QString>
#include <QDir>

#include <iostream>

// 检测文件格式，是否有 Desktop Entry 等必要字段
bool checkFielFormat(const QString &path)
{
    QSettings setting(path, QSettings::IniFormat);
    setting.setIniCodec(QTextCodec::codecForName("utf-8"));
    QStringList keys = setting.allKeys();

    if (!keys.contains("Desktop Entry/Icon") || !keys.contains("Desktop Entry/Exec")) {
        return false;
    }

    QLocale locale;
    if (locale.language() == QLocale::Chinese) {
        if (keys.contains("Desktop Entry/Name[zh_CN]")) {
            return true;
        }
    } else {
        if (keys.contains("Desktop Entry/Name")) {
            return true;
        }
    }

    return false;
}

// 获取 ini 文件的值，输入为文件路径和键
QString getIniValue(const QString &path, const QString &key)
{
    QSettings setting(path, QSettings::IniFormat);
    setting.setIniCodec(QTextCodec::codecForName("utf-8"));

    return setting.value(key).toString();
}

// 执行命令接口，入参：命令及参数，出参：输出
bool executeCmd(QString cmd, QString &result)
{
    QProcess proc;
    proc.start("bash", QStringList() << "-c" << cmd);
    proc.waitForFinished();
    result = QString::fromLatin1(proc.readAll());
    proc.close();
    if (result.isEmpty())
        return false;

    return true;
}

/**
 * @brief mkMutiDir  创建多级目录
 * @param path       未创建的目录
 * @return       返回已创建的目录
 */
QString mkMutiDir(const QString path)
{
    QDir dir(path);
    if (dir.exists(path)) {
        return path;
    }
    QString parentDir = mkMutiDir(path.mid(0, path.lastIndexOf('/')));
    QString dirname = path.mid(path.lastIndexOf('/') + 1);
    QDir parentPath(parentDir);
    if (!dirname.isEmpty())
        parentPath.mkpath(dirname);

    return parentDir + "/" + dirname;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationVersion("Version: 1.0.1");

    QCommandLineParser parser;
    parser.setApplicationDescription("Description: This is example of console application");

    parser.addHelpOption();
    parser.addVersionOption();

    // 指定 -d，必须有一个值
    QCommandLineOption desktopOpt(QStringList() << "d" << "path", "desktop path", "desktoppath");
    parser.addOption(desktopOpt);

    // 指定 -n，无值
    QCommandLineOption nameOpt(QStringList() << "n" << "name", "program name");
    parser.addOption(nameOpt);

    // 指定 -i，无值
    QCommandLineOption iconOpt(QStringList() << "i" << "icon", "program icon");
    parser.addOption(iconOpt);

    // 指定 -e，必须有一个值
    QCommandLineOption execOpt(QStringList() << "e" << "exepath", "program path", "programpath");
    parser.addOption(execOpt);

    parser.process(a);

    const QStringList args = parser.optionNames();  // 获取所有的参数设置
    if (args.size() != 2) {
        fprintf(stderr, "%s\n", qPrintable(QCoreApplication::translate("main", "Error: Argument count != 2.")));
        parser.showHelp(1);
    }

    QString desktopPath = parser.value(desktopOpt);

    // 检测文件格式，如果不满足返回1
    if (!checkFielFormat(desktopPath))
        return 1;

    if (parser.isSet(nameOpt)) {
        QLocale locale;
        if (locale.language() == QLocale::Chinese)
            std::cout << getIniValue(desktopPath, "Desktop Entry/Name[zh_CN]").toStdString() << std::endl;
        else
            std::cout << getIniValue(desktopPath, "Desktop Entry/Name").toStdString() << std::endl;
    }

    if (parser.isSet(iconOpt)) {
        QString iconPath = getIniValue(desktopPath, "Desktop Entry/Icon");
        if (QFile::exists(iconPath)) {
            std::cout << iconPath.toStdString() << std::endl;
        } else {
//            QFileInfo fileInfo(iconPath);
//            mkMutiDir(fileInfo.absolutePath());
//            QFile file(iconPath);
//            file.open(QIODevice::WriteOnly);
//            file.close();

//            if (QFile::exists(iconPath)) {
//                std::cout << iconPath.toStdString() << std::endl;
//            }

            QFile file("/tmp/icon.svg");
            file.open(QIODevice::WriteOnly);
            file.write(iconPath.toUtf8());
            file.close();
            std::cout << file.fileName().toStdString() << std::endl;
        }
    }

    if (parser.isSet(execOpt)) {
        QString exec = getIniValue(desktopPath, "Desktop Entry/Exec");
        QString parameter = parser.value(execOpt);

        QString cmd = QString("%1 %2").arg(exec, parameter);

        QString result;
        executeCmd(cmd, result);
        std::cout << result.toStdString() << std::endl;
    }
}
