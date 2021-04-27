#include "todomodel.h"

#include <QLineEdit>
#include <QDebug>

ItemDelegate::ItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *ItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    return editor;
}

void ItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString text = index.data().toString();
    QLineEdit *lineEdit = static_cast<QLineEdit *>(editor);

    if (lineEdit == Q_NULLPTR)
        return;

    lineEdit->setText(text);
}

void ItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *lineEdit = static_cast<QLineEdit *>(editor);
    if (lineEdit == Q_NULLPTR || lineEdit->text().trimmed().isEmpty())
        return;

    QString text = lineEdit->text();
    model->setData(index, text, Qt::EditRole);
}

TodoModel::TodoModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QModelIndex TodoModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex TodoModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int TodoModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

int TodoModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return m_list.count();

    return 0;
}

QVariant TodoModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int column = index.column();

    if (row >= m_list.count())
        return QVariant();

    QString listContent = m_list.at(row);

    switch (role) {
    case Qt::DisplayRole: {
        if (0 == column)
            return listContent.trimmed();

        break;
    }
    default:
        break;
    }

    return QVariant();
}

bool TodoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;

    int row = index.row();
    int column = index.column();

    if (row >= m_list.count())
        return false;

    switch (role) {
    case Qt::EditRole: {
        if (0 == column) {
            m_list[row] = value.toString();
            return true;
        }

        break;
    }
    default:
        break;
    }

    return false;
}

bool TodoModel::removeRows(int row, int count, const QModelIndex &parent)
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

Qt::ItemFlags TodoModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return QAbstractItemModel::flags(index);

    if (0 == index.column()) {
        Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
        return flags;
    }

    return QAbstractItemModel::flags(index);
}

void TodoModel::insertItem(const QString &record, int row, const QModelIndex &parent)
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
