#include "task.h"
#include <QSettings>

TaskSearchGitRepository::TaskSearchGitRepository()
{
    m_bDebug = false;
    m_pWriter = NULL;
};

QString TaskSearchGitRepository::help()
{
    return "\t--debug - viewing debug messages";
};

QString TaskSearchGitRepository::name()
{
    return "SearchGitRepository";
};

QString TaskSearchGitRepository::author()
{
    return "Evgenii Sopov <mrseakg@gmail.com>";
};

QString TaskSearchGitRepository::description()
{
    return "Task is search git-repository";
};

bool TaskSearchGitRepository::isSupportOS(const coex::ITypeOperationSystem *)
{
    return true; // any os
};

void TaskSearchGitRepository::setOption(QStringList options)
{
    if (options.contains("--debug"))
        m_bDebug = true;
};

void TaskSearchGitRepository::processGitFolder(QString gitfolder)
{
	QString gitconfig = gitfolder + "/config";
	if(QFile::exists(gitconfig)){
		QString path = QFileInfo(gitfolder + "/..").absoluteFilePath();
		QString id = "gitrepo_" + QCryptographicHash::hash(path.toUtf8(), QCryptographicHash::Md5).toHex();
		QString url = "";
		
		QSettings *pSettings = new QSettings(gitconfig,QSettings::IniFormat);
		QStringList groups = pSettings->childGroups();
		
		for(int i = 0; i < groups.size(); i++){
			QString key = groups[i] + "/url";
			if(pSettings->contains(key)){
				if(url == "")
					url = pSettings->value(key).toString();
				else
					url += ", " + pSettings->value(key).toString();
			}
		}
		if(m_bDebug)
			std::cout << path.toStdString() << " => " << url.toStdString() << "\n";

		m_pWriter->writeStartElement("doc");
		writeField("id", id);
		writeField("application", "Git");
		writeField("doc_type", "gitrepo");
		writeField("gitrepo_url", url);
		writeField("gitrepo_path", path);
		// writeField("gitrepo_other", url);
		m_pWriter->writeEndElement();
	}
}

void TaskSearchGitRepository::writeField(QString sName, QString sValue)
{
	if(m_pWriter != NULL){
		m_pWriter->writeStartElement("field");
		m_pWriter->writeAttribute("name", sName);
		m_pWriter->writeCharacters(sValue);
		m_pWriter->writeEndElement();
	}
}

void TaskSearchGitRepository::writeStartAdd(){
	if(m_pWriter != NULL){
		m_pWriter->setAutoFormatting(true);
		m_pWriter->setAutoFormattingIndent(2);
		m_pWriter->writeStartDocument();
		m_pWriter->writeStartElement("add");
	}
};

void TaskSearchGitRepository::writeEndAdd(){
	if(m_pWriter != NULL){
		m_pWriter->writeEndElement();
        m_pWriter->writeEndDocument();
        m_pWriter = NULL;
	}
};

bool TaskSearchGitRepository::execute(const coex::IConfig *config)
{
    if (m_bDebug) {
        qDebug() << "==========TaskSearchGitRepository::execute==========\n";
        qDebug() << " * Debug mode: On";
        qDebug() << " * InputFolder: " << config->inputFolder();
        qDebug() << " * OutputFolder: " << config->outputFolder() << "\n";
    };
    QDir inputDir(config->inputFolder());
    QDir outputDir(config->outputFolder());
    
    // scanDir(outputDir);
    
    outputDir.mkdir("gitrepos");
    QStringList extensions = (QStringList() << ".git");
    QFile xmlfile(outputDir.absolutePath() + "/gitrepos/gitrepos.xml");
    xmlfile.open(QFile::WriteOnly);
    m_pWriter = new QXmlStreamWriter(&xmlfile);
    writeStartAdd();
    QDirIterator fileListDirit(inputDir.absolutePath(), extensions, QDir::Files | QDir::NoSymLinks | QDir::Hidden | QDir::System | QDir::AllEntries, QDirIterator::Subdirectories);
    while (fileListDirit.hasNext())
    {
        QString str = QString("%1").arg(fileListDirit.next());
		processGitFolder(str);
    }
    writeEndAdd();
    if (m_bDebug) {
        qDebug() << "\n==========TaskSearchGitRepository::finish==========\n\n";
    };
    return true;
}



