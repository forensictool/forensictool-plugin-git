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
    setMinimumSize(1000, 600);

    initWidgets();
	


    // btnGenerateSignal();
	// m_pThread = new HandSearchThread();
	// connect(m_pThread, SIGNAL(updateKFW(QString)), SLOT(onUpdateKFW(QString)));
                          
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::initWidgets(){
    // Main Layout
    m_pMainLayout = new QVBoxLayout();

    // Top panel with info
    {
        QHBoxLayout *pLayouts = new QHBoxLayout();

        // TODO: logo
        QLabel *pLabel1 = new QLabel("LOGO");
        pLabel1->setFixedWidth(70);
        pLabel1->setFixedHeight(70);
        pLayouts->addWidget(pLabel1);

        // Author & Version
        QString version = QString::number(VERSION_MAJOR) + "." + QString::number(VERSION_MINOR) + "." + QString::number(VERSION_BUILD);
        QString text = "";
        text += "Description: " + m_pTask->description() + "\n";
        text += "Author: " + m_pTask->author() + "\n";
        text += "Version: " + version + "\n";

        QLabel *pLabel2 = new QLabel(text);
        pLayouts->addWidget(pLabel2);


        QWidget *pWidget = new QWidget();
        pWidget->setFixedHeight(70);
        pWidget->setLayout(pLayouts);
        m_pMainLayout->addWidget(pWidget);
    }

    initEditor();

    QWidget *pWidget = new QWidget();
    pWidget->setLayout(m_pMainLayout);
    setCentralWidget(pWidget);
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::initEditor(){
	QVBoxLayout *pLayouts;
	pLayouts = new QVBoxLayout();
	QLabel *pLabel1 = new QLabel("FFT");
	pLabel1->setFixedHeight(25);
	m_pTextEdit = new QTextEdit();
	m_pTextEdit->setText("# like this: K*sin(W*t)\n-1.0*sin(3.14*t-1.8)\n10*cos(3.14*t+0.1)");
	loadFromFile();
	m_pTextEditLog = new QTextEdit();
	m_pTextEditLog->setText("Started...");
	m_pTextEditLog->setReadOnly(true);
	m_pBtnGenerate = new QPushButton("Generate");
	connect(m_pBtnGenerate, SIGNAL(clicked()), this, SLOT(btnGenerateSignal()));
	m_pBtnRunGeneticAlg = new QPushButton("Run Genetic Algorithm");
	connect(m_pBtnRunGeneticAlg, SIGNAL(clicked()), this, SLOT(btnRunGeneticAlgorithm()));

	pLayouts->addWidget(pLabel1);
	pLayouts->addWidget(m_pTextEdit);
	pLayouts->addWidget(m_pTextEditLog);
	pLayouts->addWidget(m_pBtnGenerate);
	pLayouts->addWidget(m_pBtnRunGeneticAlg);
	
	QWidget *pWidget = new QWidget();
	pWidget->setFixedWidth(250);
	pWidget->setLayout(pLayouts);
	m_pMainLayout->addWidget(pWidget);
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::btnRunGeneticAlgorithm() {
	/*if(m_pThread->isRunning()){
		m_pThread->terminate();
		m_pBtnGenerate->setEnabled(true);
		m_pBtnRunGeneticAlg->setText("Run Genetic Algorithm");
		m_pTextEdit->setReadOnly(false);
	}else{
		m_pTextEdit->setReadOnly(true);
		m_pBtnGenerate->setEnabled(false);
		m_pBtnRunGeneticAlg->setText("Stop Genetic Algorithm");
		
		m_pTextEditLog->setText("");
		m_pTextEditLog->append("Run Genetic Algorithm...");
		m_pTextEditLog->append("Previous MiddleDiff: " + QString::number(m_nMiddleDiff));
	
		QString sLines = m_pTextEdit->toPlainText();
		QStringList lines = sLines.split("\n");
		QVector<KFW> vKFW;
		parseFuncs(lines, vKFW);
		m_pThread->setKFW(vKFW);
		m_pThread->setOriginalSignal(m_vOriginalSignal);
		m_pThread->start();
	}*/
}

// ---------------------------------------------------------------------

void GitSearchRepoWindow::btnGenerateSignal() {
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
