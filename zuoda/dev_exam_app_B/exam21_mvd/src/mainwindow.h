#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "todomodel.h"
#include "todoview.h"

class QStandardItemModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class AutoTest;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onAddItem();
    void onDeleteItem();

private:
    Ui::MainWindow *ui;
    TodoModel *model;
    TodoView *view;
    ItemDelegate *p;

    QItemSelectionModel *selectionModel;
};

#endif // MAINWINDOW_H
