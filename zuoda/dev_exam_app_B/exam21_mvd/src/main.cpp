#include <iostream>
#include "autotest.h"

/**
 * 编写一个todo程序，功能及要求如下：
 *
 * - 实现的功能是：添加、删除、修改todo项目。
 * - todo列表继承QListView，不许使用QListWidget。数据Model继承QAbstractItemModel。
 * - 界面上有这几个元素（如何布局不做强制要求）：
 *   - todo列表控件：按行显示todo items。单击选中一个todo，双击原地修改todo的内容
 *   - 一个QLineEdit用于输入todo条目的内容
 *   - 一个QPushButton实现’添加‘新的todo，QLineEdit为空，disabled
 *   - 一个QPushButton实现’删除‘选择的todo，没有选择一个todo，disabled
 */

QTEST_MAIN(AutoTest)

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}
