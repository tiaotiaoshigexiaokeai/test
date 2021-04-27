#ifndef TODOVIEW_H
#define TODOVIEW_H

#include <QWidget>
#include <QListView>
#include <QStyledItemDelegate>
#include "todomodel.h"

class TodoView : public QListView
{
    Q_OBJECT
public:
    explicit TodoView(QWidget *parent = nullptr);

signals:

public slots:

};

#endif // TODOVIEW_H
