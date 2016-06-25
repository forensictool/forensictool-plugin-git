#include "window.h"
#include <QWheelEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QFileInfo>
#include <qmath.h>
#include <iostream>
#include <QApplication>
#include <QDir>
#include <QIcon>
#include <QFileDialog>
#include <QRegExp>
#include <QPen>
#include <QDir>
#include <QHeaderView>
#include "../task.h"
#include "../forensictool-core/v0.3.1/helpers/config.h"
#include "../forensictool-core/v0.3.1/helpers/typeos.h"

GitSearchRepoWindow::GitSearchRepoWindow(){
    m_pTask = (forensictool::ITask*)(new TaskSearchGitRepository());

    setWindowTitle(m_pTask->name());
	setWindowIcon(QIcon(":/images/logo_70x70.png"));
    initWidgets();
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::initWidgets(){
    // Main Layout
    m_pMainLayout = new QVBoxLayout();
    m_pMainLayout->setContentsMargins(10,10,10,10);

    // Top panel with info
    {
        QHBoxLayout *pLayout = new QHBoxLayout();

        QLabel *pLabel1 = new QLabel();
        pLabel1->setFixedWidth(70);
        pLabel1->setFixedHeight(70);

		pLabel1->setStyleSheet("background-image: url(:/images/logo_70x70.png);");
        pLayout->addWidget(pLabel1);

        // description
        {
            QVBoxLayout *pLayout1 = new QVBoxLayout();

            QLabel *pLabelDescr = new QLabel("Description: " + m_pTask->description());
            pLayout1->addWidget(pLabelDescr);

            QLabel *pLabelAuthor = new QLabel("Authors: " + m_pTask->authors().join(", "));
            pLayout1->addWidget(pLabelAuthor);

            QString version = QString::number(VERSION_MAJOR) + "." + QString::number(VERSION_MINOR) + "." + QString::number(VERSION_BUILD);
            QLabel *pLabelVersion = new QLabel("Version: " + version);
            pLayout1->addWidget(pLabelVersion);

            QWidget *pWidget = new QWidget();
            pWidget->setLayout(pLayout1);
            pLayout->addWidget(pWidget);
        }
		
		pLayout->setSpacing(10);
		pLayout->setContentsMargins(0,0,0,0);
        QWidget *pWidget = new QWidget();
        pWidget->setLayout(pLayout);
        m_pMainLayout->addWidget(pWidget);
    }

    // input folder
    {
		QHBoxLayout *pLayout = new QHBoxLayout();
		
		QLabel *pLabel = new QLabel("Input folder: ");
		pLayout->addWidget(pLabel);
		
        m_pInputFolder = new QLineEdit();
        m_pInputFolder->setReadOnly(true);
        pLayout->addWidget(m_pInputFolder);
		
		QPushButton *pPushButton = new QPushButton("Select...");
		pLayout->addWidget(pPushButton);
		
        connect(pPushButton, SIGNAL(clicked()), this, SLOT(btnChooseInputFolder()));

		pLayout->setSpacing(0);
		pLayout->setContentsMargins(0,0,0,0);
        pLayout->setMargin(0);
		QWidget *pWidget = new QWidget();
        pWidget->setLayout(pLayout);
        m_pMainLayout->addWidget(pWidget);
    }

	// manage panel
    {
		QHBoxLayout *pLayout = new QHBoxLayout();

        m_pButtonStart = new QPushButton("Start");
        m_pButtonStart->setFixedWidth(100);
        pLayout->addWidget(m_pButtonStart);
        connect(m_pButtonStart, SIGNAL(clicked()), this, SLOT(btnStart()));

		/*QLabel *pLabel = new QLabel("Search: ");
		pLayout->addWidget(pLabel);
		
		QLineEdit *pLineEdit = new QLineEdit();
		pLineEdit->setReadOnly(true);
		pLayout->addWidget(pLineEdit);
		
		QPushButton *pPushButton1 = new QPushButton("Search");
		pLayout->addWidget(pPushButton1);*/
		
		QWidget *pWidget = new QWidget();
        pWidget->setLayout(pLayout);
        m_pMainLayout->addWidget(pWidget);
	}
	
	// table
	{
		QTableView* pTableView = new QTableView();
        pTableView->setColumnWidth(0, 300);
        pTableView->setColumnWidth(1, 400);
        // pTableView->horizontalHeader()->sectionResizeMode(QHeaderView::Stretch);

        m_pTableModel_GitRepos = new TableModelGitRepos();
        pTableView->setModel( m_pTableModel_GitRepos );
        m_pMainLayout->addWidget(pTableView);
	}

    QWidget *pWidget = new QWidget();
    pWidget->setLayout(m_pMainLayout);
    setCentralWidget(pWidget);
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::btnChooseInputFolder(){
    QString path = QDir::home().absolutePath();
    if(m_pInputFolder->text() != "")
        path = m_pInputFolder->text();
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 path,
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    if(dir != "")
        m_pInputFolder->setText(dir);
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::btnStart() {

    QString outputDir = QDir::home().absolutePath() + "/forensictool.output";
    if(!QDir(outputDir).exists()){
        QDir().mkdir(outputDir);
    }

    forensictool::IConfig *pConfig = (forensictool::IConfig *)(new Config());

    pConfig->setInputFolder(m_pInputFolder->text());
    pConfig->setOutputFolder(outputDir);
    pConfig->setTypeOS((forensictool::ITypeOperationSystem *)(new TypeOS()));

    QStringList args;
    pConfig->setParameters(args);
    m_pTask->init(pConfig);
    m_pTask->execute();

    m_pTableModel_GitRepos->reloadDataFromXML();
    m_pTableModel_GitRepos->needReset();
}

// ---------------------------------------------------------------------

void GitSearchRepoWindowThread::run(){

}

// ---------------------------------------------------------------------
