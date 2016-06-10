#include "tablemodel_gitrepos.h"

TableModelGitRepos::TableModelGitRepos()
{
    m_columnPath << "test1" << "test222222222";
    m_columnUrl << "test1" << "test2222222222";
}

// ---------------------------------------------------------------------

int TableModelGitRepos::rowCount(const QModelIndex & /*parent*/) const {
    if(m_columnUrl.size() == m_columnPath.size())
        return m_columnUrl.size();
    return 0;
}

// ---------------------------------------------------------------------

int TableModelGitRepos::columnCount(const QModelIndex & /*parent*/) const {
    return 2;
}

// ---------------------------------------------------------------------

QVariant TableModelGitRepos::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {

        if (index.row() < m_columnPath.size() && index.column() == 0) {
            return m_columnPath[index.row()];
        }
        if (index.row() < m_columnUrl.size() && index.column() == 1) {
            return m_columnUrl[index.row()];
        }
    }
    return QVariant();
}

// ---------------------------------------------------------------------

QVariant TableModelGitRepos::headerData(int section, Qt::Orientation  orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        if (section == 0)
            return "Path";
        else if (section == 1)
            return "Git URL";
        else
            return QVariant();
    }
    if (orientation == Qt::Vertical && role == Qt::DisplayRole) {
        return section + 1;
    }
    return QVariant();
}

// ---------------------------------------------------------------------

void TableModelGitRepos::needReset() {
    emit layoutChanged();
}
