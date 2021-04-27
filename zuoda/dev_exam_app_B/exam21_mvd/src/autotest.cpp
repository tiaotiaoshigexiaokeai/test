#include "autotest.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QLineEdit>
#include <QDebug>
#include "qtestmouse.h"

AutoTest::AutoTest(QObject *parent) : QObject(parent)
{

}

// 模拟行编辑器与添加按钮的联动效果
void AutoTest::testGui()
{
    QFETCH(QTestEventList, testLineEdit);
    QFETCH(bool, result);

    MainWindow window;
    window.show();
    testLineEdit.simulate(window.ui->lineEdit);
    bool b = window.ui->addButton->isEnabled();
    QCOMPARE(b, result);
}

void AutoTest::testGui_data()
{
    QTest::addColumn<QTestEventList>("testLineEdit");
    QTest::addColumn<bool>("result");

    QTestEventList testList1;
    testList1.addKeyClicks("sdgfdhgfh");
    QTest::newRow("row1") << testList1 << true;

    QTestEventList testList2;
    testList2.addKeyClicks("");
    QTest::newRow("row2") << testList2 << false;

    QTestEventList testList3;
    testList3.addKeyClicks(" ");
    QTest::newRow("row3") << testList3 << false;

    QTestEventList testList4;
    testList4.addKeyClicks(" efhuj");
    QTest::newRow("row4") << testList4 << true;

    QTestEventList testList5;
    testList5.addKeyClicks("        ");
    QTest::newRow("row5") << testList5 << false;

    QTestEventList testList6;
    testList6.addKeyClicks("        rthtfgjh");
    QTest::newRow("row6") << testList6 << true;

    QTestEventList testList7;
    testList7.addKeyClicks(" jkhkj ");
    QTest::newRow("row7") << testList7 << true;

    QTestEventList testList8;
    testList8.addKeyClicks("jkhkj    ");
    QTest::newRow("row8") << testList8 << true;
}

// 模拟按钮添加数据
void AutoTest::testAdd()
{
    QFETCH(QTestEventList, testAdd);
    QFETCH(QString, result);

    MainWindow window;
    testAdd.simulate(window.ui->lineEdit);
    QTest::mouseClick(window.ui->addButton, Qt::LeftButton);
    QString str = window.model->data(window.model->index(window.model->rowCount() - 1, 0), Qt::DisplayRole).toString();
    QCOMPARE(str, result);

}

void AutoTest::testAdd_data()
{
    QTest::addColumn<QTestEventList>("testAdd");
    QTest::addColumn<QString>("result");

    QTestEventList testList1;
    testList1.addKeyClicks("sdgfdhgfh");
    QTest::newRow("addrow1") << testList1 << "sdgfdhgfh";

    QTestEventList testList2;
    testList2.addKeyClicks("fgddfg");
    QTest::newRow("addrow2") << testList2 << "fgddfg";

    QTestEventList testList3;
    testList3.addKeyClicks(" fgddfg");
    QTest::newRow("addrow3") << testList3 << "fgddfg";

    QTestEventList testList4;
    testList4.addKeyClicks("fgddfg  ");
    QTest::newRow("addrow4") << testList4 << "fgddfg";

    QTestEventList testList5;
    testList5.addKeyClicks("   fgddfg  ");
    QTest::newRow("addrow5") << testList5 << "fgddfg";

    QTestEventList testList6;
    testList6.addKeyClicks("fgdn  dfg");
    QTest::newRow("addrow6") << testList6 << "fgdn  dfg";

    QTestEventList testList7;
    testList7.addKeyClicks("  fgdn  dfg  ");
    QTest::newRow("addrow7") << testList7 << "fgdn  dfg";
}

// 模拟回车键添加
void AutoTest::testKeyEnterAdd()
{
    QFETCH(QTestEventList, testKeyEnterAdd);
    QFETCH(QString, result);

    MainWindow window;
    testKeyEnterAdd.simulate(window.ui->lineEdit);
    QString str = window.model->data(window.model->index(window.model->rowCount() - 1, 0), Qt::DisplayRole).toString();
    QCOMPARE(str, result);
}

void AutoTest::testKeyEnterAdd_data()
{
    QTest::addColumn<QTestEventList>("testKeyEnterAdd");
    QTest::addColumn<QString>("result");

    QTestEventList testList1;
    testList1.addKeyClicks("sdgfdhgfh");
    testList1.addKeyClick(Qt::Key_Enter);
    QTest::newRow("keyenteraddrow1") << testList1 << "sdgfdhgfh";

    QTestEventList testList2;
    testList2.addKeyClicks("fgddfg");
    testList2.addKeyClick(Qt::Key_Enter);
    QTest::newRow("keyenteraddrow2") << testList2 << "fgddfg";

    QTestEventList testList3;
    testList3.addKeyClicks(" fgddfg");
    testList3.addKeyClick(Qt::Key_Enter);
    QTest::newRow("keyenteraddrow3") << testList3 << "fgddfg";

    QTestEventList testList4;
    testList4.addKeyClicks("fgddfg  ");
    testList4.addKeyClick(Qt::Key_Enter);
    QTest::newRow("keyenteraddrow4") << testList4 << "fgddfg";

    QTestEventList testList5;
    testList5.addKeyClicks("   fgddfg  ");
    testList5.addKeyClick(Qt::Key_Enter);
    QTest::newRow("keyenteraddrow5") << testList5 << "fgddfg";

    QTestEventList testList6;
    testList6.addKeyClicks("fgdn  dfg");
    testList6.addKeyClick(Qt::Key_Enter);
    QTest::newRow("keyenteraddrow6") << testList6 << "fgdn  dfg";

    QTestEventList testList7;
    testList7.addKeyClicks("  fgdn  dfg  ");
    testList7.addKeyClick(Qt::Key_Enter);
    QTest::newRow("keyenteraddrow7") << testList7 << "fgdn  dfg";
}


// 模拟单击删除
void AutoTest::testDelete()
{
    MainWindow window;
    QTest::keyClicks(window.ui->lineEdit, "eewf");
    QTest::mouseClick(window.ui->addButton, Qt::LeftButton);
    QString str = window.model->data(window.model->index(window.model->rowCount() - 1, 0), Qt::DisplayRole).toString();
    QCOMPARE(str, "eewf");

    QTest::keyClicks(window.ui->lineEdit, "1111");
    QTest::mouseClick(window.ui->addButton, Qt::LeftButton);
    QString str1 = window.model->data(window.model->index(window.model->rowCount() - 1, 0), Qt::DisplayRole).toString();
    QCOMPARE(str1, "1111");

    QRect rect = window.view->visualRect(window.model->index(0, 0));
    QTest::mouseClick(window.view->viewport(), Qt::LeftButton, Qt::KeyboardModifiers(), rect.center());
    int beforeCount = window.model->rowCount();
    QTest::mouseClick(window.ui->deleteButton, Qt::LeftButton);
    int afterCount = window.model->rowCount();
    QCOMPARE(afterCount, beforeCount - 1);
}

// 模拟双击编辑
void AutoTest::testEditor()
{
    MainWindow window;
    QTest::keyClicks(window.ui->lineEdit, "eewf");
    QTest::mouseClick(window.ui->addButton, Qt::LeftButton);
    QString str = window.model->data(window.model->index(window.model->rowCount() - 1, 0), Qt::DisplayRole).toString();
    QCOMPARE(str, "eewf");

    QTest::keyClicks(window.ui->lineEdit, "1111");
    QTest::mouseClick(window.ui->addButton, Qt::LeftButton);
    QString str1 = window.model->data(window.model->index(window.model->rowCount() - 1, 0), Qt::DisplayRole).toString();
    QCOMPARE(str1, "1111");

    QTest::keyClicks(window.ui->lineEdit, "44444444");
    QTest::mouseClick(window.ui->addButton, Qt::LeftButton);
    QString str2 = window.model->data(window.model->index(window.model->rowCount() - 1, 0), Qt::DisplayRole).toString();
    QCOMPARE(str2, "44444444");


    // 正常输入情况
    QStringList list;
    list << "kwefhduighf" << "12213234"<< "thnghghng" << "84ty8475y859" << "dkfhgufidhguf";

    for (int i = 0; i < list.count(); i++) {
        QString strData = list.at(i);

        int nRow = i % window.model->rowCount();
        QRect rect = window.view->visualRect(window.model->index(nRow, 0));
        QTest::mouseDClick(window.view->viewport(), Qt::LeftButton, Qt::KeyboardModifiers(), rect.center());
        window.view->edit(window.view->currentIndex());
        QTest::keyClicks(window.view->focusWidget(),strData);
        QTest::keyClick(window.view->focusWidget(), Qt::Key_Enter,Qt::NoModifier, 200);

        QString currStr = window.model->data(window.view->currentIndex(), Qt::DisplayRole).toString();
        QCOMPARE(currStr, strData);
    }

    // 输入带空格和tab键的情况
    list.clear();
    list << "  kwefhduighf  " << "   12213234" << "thnghghng   " << "84ty84   75y859" << "   dkfhgufidhguf   ";
    for (int i = 0; i < list.count(); i++) {
        QString strData = list.at(i);

        int nRow = i % window.model->rowCount();
        QRect rect = window.view->visualRect(window.model->index(nRow, 0));
        QTest::mouseDClick(window.view->viewport(), Qt::LeftButton, Qt::KeyboardModifiers(), rect.center());
        window.view->edit(window.view->currentIndex());
        QTest::keyClicks(window.view->focusWidget(),strData);
        QTest::keyClick(window.view->focusWidget(), Qt::Key_Enter,Qt::NoModifier, 200);

        QString currStr = window.model->data(window.view->currentIndex(), Qt::DisplayRole).toString();
        QCOMPARE(currStr, strData.trimmed());
    }

    // 输入纯空格和tab键
    list.clear();
    list << " " << "    " << "          " << "          " << "              ";
    for (int i = 0; i < list.count(); i++) {
        QString strData = list.at(i);

        int nRow = i % window.model->rowCount();
        QString strBefore = window.model->data(window.model->index(nRow, 0), Qt::DisplayRole).toString();
        QRect rect = window.view->visualRect(window.model->index(nRow, 0));
        QTest::mouseDClick(window.view->viewport(), Qt::LeftButton, Qt::KeyboardModifiers(), rect.center());
        window.view->edit(window.view->currentIndex());
        QTest::keyClicks(window.view->focusWidget(),strData);
        QTest::keyClick(window.view->focusWidget(), Qt::Key_Enter,Qt::NoModifier, 200);

        QString strAfter = window.model->data(window.view->currentIndex(), Qt::DisplayRole).toString();
        QCOMPARE(strAfter, strBefore);
    }
}

