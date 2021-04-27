#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include <QStyledItemDelegate>
#include <QListView>

namespace Ui {
class MainWindow;
}

struct ListContent {
    Qt::GlobalColor color;
    QString text;
};

class ItemDelegate : public QStyledItemDelegate
{
public:
    ItemDelegate(QObject *parent = nullptr) {}
};

class ListModel : public QAbstractItemModel
{

    Q_OBJECT
public:
    explicit ListModel(QObject *parent = nullptr);
    ~ListModel();

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &child) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;

public:
    void insertItem(const ListContent &record, int row, const QModelIndex &parent = QModelIndex());

private:
    QList<ListContent> m_list;
};

class ListView : public QListView
{
    Q_OBJECT
public:
    explicit ListView(QWidget *parent = nullptr);
    ~ListView();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class autoTest;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUI();
    void initConnection();

public slots:
    void onAddItem();
    void onDeleteItem();

private:
    Ui::MainWindow *ui;
    ListModel *m_Model;
    ItemDelegate *m_Delegate;
//    ListView *m_ListView;
    QListView *m_ListView;

    QItemSelectionModel *selectionModel;
    QMap<QString, Qt::GlobalColor> m_map;
};

#endif // MAINWINDOW_H
