#include "todoview.h"

#include <QMouseEvent>
#include <QDebug>
#include <QLineEdit>

TodoView::TodoView(QWidget *parent) : QListView(parent)
{
    setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerItem); // 设置垂直滚动模式
    // setFrameShape(QFrame::NoFrame); // 无边框设置
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows); // 抽象选择行
    // viewport()->setAutoFillBackground(false);
}

