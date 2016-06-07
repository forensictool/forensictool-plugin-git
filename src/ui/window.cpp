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
#include "../task.h"

GitSearchRepoWindow::GitSearchRepoWindow(){
    m_pTask = (coex::ITask*)(new TaskSearchGitRepository());

    setWindowTitle(m_pTask->name());
    // setMinimumSize(1000, 600);
	setWindowIcon(QIcon(":/images/logo_70x70.png"));
    initWidgets();
	
// QSizePolicy::Expanding

    // btnGenerateSignal();
	// m_pThread = new HandSearchThread();
	// connect(m_pThread, SIGNAL(updateKFW(QString)), SLOT(onUpdateKFW(QString)));
                          
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::initWidgets(){
    // Main Layout
    m_pMainLayout = new QVBoxLayout();
	m_pMainLayout->setContentsMargins(10,10,10,10);
    // Top panel with info
    {
        QHBoxLayout *pLayout = new QHBoxLayout();

		// QImage *pImage = new QImage(":/images/logo_70x70.png");

        // TODO: logo
        QLabel *pLabel1 = new QLabel();
        pLabel1->setFixedWidth(70);
        pLabel1->setFixedHeight(70);
        
        // QPixmap pix(":/images/logo_70x70.png");
		pLabel1->setStyleSheet("background-image: url(:/images/logo_70x70.png);");
		// pLabel1->setPixmap(pix);
        pLayout->addWidget(pLabel1);

        // Author & Version
        QString version = QString::number(VERSION_MAJOR) + "." + QString::number(VERSION_MINOR) + "." + QString::number(VERSION_BUILD);
        QString text = "";
        text += "Description: " + m_pTask->description() + "\n";
        text += "Author: " + m_pTask->author() + "\n";
        text += "Version: " + version + "\n";

        QLabel *pLabel2 = new QLabel(text);
        pLayout->addWidget(pLabel2);
		
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
		
		QLineEdit *pLineEdit = new QLineEdit();
		pLineEdit->setReadOnly(true);
		pLayout->addWidget(pLineEdit);
		
		QPushButton *pPushButton = new QPushButton("Select...");
		pLayout->addWidget(pPushButton);
		
		pLayout->setSpacing(0);
		pLayout->setContentsMargins(0,0,0,0);
		QWidget *pWidget = new QWidget();
        pWidget->setLayout(pLayout);
        m_pMainLayout->addWidget(pWidget);
	}
	
	// ouput folder
    {
		QHBoxLayout *pLayout = new QHBoxLayout();
		
		QLabel *pLabel = new QLabel("Output folder: ");
		pLayout->addWidget(pLabel);
		
		QLineEdit *pLineEdit = new QLineEdit();
		pLineEdit->setReadOnly(true);
		pLayout->addWidget(pLineEdit);
		
		QPushButton *pPushButton = new QPushButton("Select...");
		pLayout->addWidget(pPushButton);
		
		pLayout->setSpacing(0);
		pLayout->setContentsMargins(0,0,0,0);
		QWidget *pWidget = new QWidget();
        pWidget->setLayout(pLayout);
        m_pMainLayout->addWidget(pWidget);
	}
	
	// manage panel
    {
		QHBoxLayout *pLayout = new QHBoxLayout();

		QPushButton *pPushButton = new QPushButton("Run");
		pLayout->addWidget(pPushButton);
		
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
        m_pMainLayout->addWidget(pTableView);
	}

    QWidget *pWidget = new QWidget();
    pWidget->setLayout(m_pMainLayout);
    setCentralWidget(pWidget);
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::btnStart() {
	/*QString sLines = m_pTextEdit->toPlainText();
	QStringList lines = sLines.split("\n");
	QVector<KFW> vKFW;
	parseFuncs(lines, vKFW);
	QStringList newLines;
	for(int i = 0; i < vKFW.size(); i++){
		newLines << vKFW[i].toString();
	}
	m_pTextEdit->setText(newLines.join("\n"));
	saveToFile();
	recalcSignals(vKFW);
	m_pTextEditLog->append("Current MiddleDiff: " + QString::number(m_nMiddleDiff));
	updateGraphs();*/
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::onUpdateKFW(QString kfwlist){
	// std::cout << "update KFW 2\n";
	/*QStringList lines = kfwlist.split("\n");
	QVector<KFW> vKFW;
	parseFuncs(lines, vKFW);
	QStringList newLines;
	for(int i = 0; i < vKFW.size(); i++){
		newLines << vKFW[i].toString();
	}
	m_pTextEdit->setText(newLines.join("\n"));
	saveToFile();
	recalcSignals(vKFW);
	m_pTextEditLog->append("Updated MiddleDiff: " + QString::number(m_nMiddleDiff));
	updateGraphs();*/
}

// ---------------------------------------------------------------------		

void GitSearchRepoWindow::loadFromFile(){
	/*if(QFile::exists("last_signal.txt")){
		QFile file("last_signal.txt");
		file.open(QIODevice::ReadOnly | QIODevice::Text);
		QTextStream in(&file);
		QStringList text;
		while (!in.atEnd()) {
			QString line = in.readLine();
			text << line;
		}
		m_pTextEdit->setText(text.join("\n"));
		file.close();
	}*/
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::saveToFile(){
	/*QFile file("last_signal.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream out(&file);
	out << m_pTextEdit->toPlainText();
	file.close();*/
}

// ---------------------------------------------------------------------

void GitSearchRepoWindowThread::run(){
	/*double nPrevDiff = calcDiffOfSignals(m_vKFW, m_vOriginalSignal);

	int nIters = 0;
	while(nPrevDiff > 0){
		nIters++;
		nPrevDiff = calcDiffOfSignals(m_vKFW, m_vOriginalSignal);
		// std::cout << "1\n";

		QVector<KFW> vTmpKFW;
		qsrand (QDateTime::currentMSecsSinceEpoch());
		int nCount = qrand()%5 + 1;
		int nMethods = 13;
		std::cout << "Methods:";
		QVector<int> m;
		for(int i = 0; i < nCount; i++){
			int mr = qrand()%nMethods;
			std::cout << " " << mr;
			m.push_back(mr);
		}
		std::cout << "\n";
		copyKFWTo(vTmpKFW);
		for(int i = 0; i < nCount; i++){
			modify(m[i], vTmpKFW);
		}
		if(check(nPrevDiff, vTmpKFW)) {
			nIters = 0;
			continue;
		}
		nIters++;
		if(nIters > 10000){
			{
				QStringList l;
				for(int i = 0; i < m_vKFW.size(); i++)
					l << m_vKFW[i].toString();
				
				QFile file("last_signal_" + QString::number(int(nPrevDiff)) + "_dt_" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".txt");
				file.open(QIODevice::WriteOnly | QIODevice::Text);
				QTextStream out(&file);
				out << l.join("\n");
				file.close();
			}

			std::cout << "force change signal\n";
			nIters = 0;
			for(int i = 0; i < 100; i++){
				modify13(vTmpKFW);
			}

			setKFW(vTmpKFW);
			QStringList l;
			for(int i = 0; i < vTmpKFW.size(); i++)
				l << vTmpKFW[i].toString();
			emit updateKFW(l.join("\n"));
			sleep(2);
		}
	}*/
}

// ---------------------------------------------------------------------
