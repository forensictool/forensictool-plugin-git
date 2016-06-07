#ifndef __GIT_SERACH_REPO_WINDOW_H__
#define __GIT_SERACH_REPO_WINDOW_H__

#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QThread>
#include <QVBoxLayout>
#include <QTableView>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include "../coex/coex.h"

class GitSearchRepoWindowThread;

class GitSearchRepoWindow : public QMainWindow
{
	// private:
		Q_OBJECT
	private:

        QVBoxLayout *m_pMainLayout;
		QTextEdit *m_pTextEdit;
		QTextEdit *m_pTextEditLog;
		QPushButton *m_pBtnRunGeneticAlg;
		QPushButton *m_pBtnGenerate;
		GitSearchRepoWindowThread *m_pThread;
        coex::ITask* m_pTask;

		int m_nSize;
		double m_nMiddleDiff;
		QVector<double> m_vOriginalSignal;
		QVector<double> m_vGeneratedSignal;
		QVector<double> m_vDiffSignal;
		QVector<double> m_vX;

        void initWidgets();
		void loadFromFile();
		void saveToFile();
	public:

		GitSearchRepoWindow();

	signals:

	public slots:
		void onUpdateKFW(QString kfwlist);

	private slots:
		void btnStart();
};

class GitSearchRepoWindowThread : public QThread
{
	private:
		Q_OBJECT
		GitSearchRepoWindow *m_pHandSearch;
		QVector<double> m_vOriginalSignal;
		double m_nMax;
		double m_nMin;
		int m_nHeightSignal;
		int m_nWidthSignal;

	public:
		void setOriginalSignal(QVector<double> vOriginalSignal);

	protected:
		void run();
	signals:
		void updateKFW(QString kfwlist);
};

#endif // __GIT_SERACH_REPO_WINDOW_H__

