#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view = new TodoView(this);
    p = new ItemDelegate(this);
    view->setItemDelegate(p);
    model = new TodoModel(this);
    view->setModel(model);

    ui->verticalLayout->addWidget(view);
    ui->addButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    selectionModel = view->selectionModel();

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddItem);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::onAddItem);

    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteItem);

    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, [ = ]() {
        ui->deleteButton->setEnabled(selectionModel->selectedIndexes().size() > 0);
    });

    connect(ui->lineEdit, &QLineEdit::textChanged, this, [ = ](const QString & text) {
        ui->addButton->setEnabled(!ui->lineEdit->text().trimmed().isEmpty());
    });

}

MainWindow::~MainWindow()
{

}

void MainWindow::onAddItem()
{
    model->insertItem(ui->lineEdit->text(), model->getData().size());
    ui->lineEdit->clear();
    ui->addButton->setEnabled(false);
}

void MainWindow::onDeleteItem()
{
//    model->removeRow(view->currentIndex().row());
    model->removeRows(view->currentIndex().row(), 1);
}

