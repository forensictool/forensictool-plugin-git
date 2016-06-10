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
#include "tablemodel_gitrepos.h"

class GitSearchRepoWindowThread;

class GitSearchRepoWindow : public QMainWindow
{
	// private:
		Q_OBJECT
	private:

        QVBoxLayout *m_pMainLayout;
        QLineEdit *m_pInputFolder;
        QPushButton *m_pButtonStart;

		GitSearchRepoWindowThread *m_pThread;
        coex::ITask* m_pTask;
        TableModelGitRepos* m_pTableModel_GitRepos;

        void initWidgets();
	public:

		GitSearchRepoWindow();

	signals:

	public slots:

	private slots:
        void btnChooseInputFolder();
        void btnStart();
};

class GitSearchRepoWindowThread : public QThread
{
	private:
		Q_OBJECT
		GitSearchRepoWindow *m_pHandSearch;

	public:
		void setOriginalSignal(QVector<double> vOriginalSignal);

	protected:
		void run();
	signals:
		void updateKFW(QString kfwlist);
};

#endif // __GIT_SERACH_REPO_WINDOW_H__

