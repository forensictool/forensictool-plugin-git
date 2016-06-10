#ifndef TABLE_MODEL_GITREPOS_H
#define TABLE_MODEL_GITREPOS_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QAbstractTableModel>
#include <QStringList>

class TableModelGitRepos : public QAbstractTableModel
{
        Q_OBJECT
    private:
        QStringList m_columnPath;
        QStringList m_columnUrl;

    public:
        TableModelGitRepos();
        int rowCount(const QModelIndex &parent = QModelIndex()) const ;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        QVariant headerData(int section, Qt::Orientation  orientation, int role) const;
        void needReset();

        void reloadDataFromXML();
};

#endif // TABLE_MODEL_GITREPOS_H
