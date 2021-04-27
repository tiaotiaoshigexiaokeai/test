#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QStyle>
#include <QPainter>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    initConnection();
    m_map.insert("red", Qt::GlobalColor::red);
    m_map.insert("black", Qt::GlobalColor::black);
    m_map.insert("white", Qt::GlobalColor::white);
    m_map.insert("purple", Qt::GlobalColor::darkBlue);
    m_map.insert("yellow", Qt::GlobalColor::yellow);
    m_map.insert("cyan", Qt::GlobalColor::cyan);
    m_map.insert("blue", Qt::GlobalColor::blue);
    m_map.insert("green", Qt::GlobalColor::green);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
//    m_ListView = new ListView(this);
    m_ListView = new QListView(this);
    m_Model = new ListModel(this);
    m_ListView->setModel(m_Model);
    QVBoxLayout *layout = new QVBoxLayout;
    ui->widget->setLayout(layout);
    layout->addWidget(m_ListView);

    selectionModel = m_ListView->selectionModel();
}

void MainWindow::initConnection()
{
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::onAddItem);
    connect(ui->btnDelete, &QPushButton::clicked, this, &MainWindow::onDeleteItem);

    connect(m_ListView, &ListView::clicked, this, [ = ]() {
        ui->btnDelete->setEnabled(m_ListView->currentIndex().isValid());
    });

    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, [ = ]() {
        ui->btnDelete->setEnabled(selectionModel->selectedIndexes().size() > 0);
    });
}

void MainWindow::onAddItem()
{
    Qt::GlobalColor color = m_map.value(ui->comboBox->currentText());
    ListContent content;
    content.text = ui->comboBox->currentText();
    content.color = color;
    m_Model->insertItem(content, 0);
}

void MainWindow::onDeleteItem()
{
    m_Model->removeRows(m_ListView->currentIndex().row(), 1);
}


ListModel::ListModel(QObject *parent)
    : QAbstractItemModel(parent)
{

}

ListModel::~ListModel()
{
}

QModelIndex ListModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex ListModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int ListModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return m_list.count();

    return 0;
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int column = index.column();
    if (row >= m_list.count())
        return QVariant();

    ListContent listContent = m_list.at(row);

    switch (role) {
    case Qt::TextAlignmentRole:
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);

    case Qt::DisplayRole: {
        if (0 == column)
            return listContent.text;

        break;
    }

    case Qt::BackgroundRole: {
        if (0 == column)
            return QColor(listContent.color);

        break;
    }

    default:
        break;
    }

    return QVariant();
}

bool ListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (-1 == row)
        return false;

    if (row >= m_list.size())
        return false;

    int romoveEnd = row + count > m_list.size() ? m_list.size() - 1 : row + count - 1;

    beginRemoveRows(parent, row, row + count - 1);

    for (int i = romoveEnd; i >= row; --i) {
        m_list.removeAt(i);
    }

    endRemoveRows();

    return true;
}

void ListModel::insertItem(const ListContent &record, int row, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row);

    if (row < 0) {
        m_list.push_front(record);
    } if (row >= m_list.size()) {
        m_list.push_back(record);
    } else {
        m_list.insert(m_list.begin() + row, record);
    }


    endInsertRows();
}

ListView::ListView(QWidget *parent)
    : QListView(parent)
{
    setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerItem); // 设置垂直滚动模式
    setFrameShape(QFrame::NoFrame); // 无边框设置
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows); // 抽象选择行
    viewport()->setAutoFillBackground(false);
}

ListView::~ListView()
{
}

