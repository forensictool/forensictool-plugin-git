#include "tablemodel_gitrepos.h"
#include <QDir>
#include <QXmlStreamReader>

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

// ---------------------------------------------------------------------

void TableModelGitRepos::reloadDataFromXML(){
    m_columnPath.clear();
    m_columnUrl.clear();
    QString outputDir = QDir::home().absolutePath() + "/coex.output";
    QFile* file = new QFile(outputDir + "/gitrepos/gitrepos.xml");
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QXmlStreamReader xml(file);
    QString lastStartElement = "";
    while (!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (xml.isStartElement()){
            if (xml.name() == "field"){
                QXmlStreamAttributes attributes = xml.attributes();
                if (attributes.hasAttribute("name")){
                    lastStartElement = attributes.value("name").toString();
                    if(lastStartElement == "gitrepo_url")
                        m_columnUrl << xml.readElementText();
                    if(lastStartElement == "gitrepo_path")
                        m_columnPath << xml.readElementText();
                }else{
                    lastStartElement = "";
                }
                continue;
            }
        }
    }

};
