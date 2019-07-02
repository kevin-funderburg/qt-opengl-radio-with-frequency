/**
* 
*  Author:   Kevin Funderburg
*  File:     mainwindow.cpp
* 
**/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QCheckBox>

class QAction;
class QListWidget;
class QMenu;

class GLobj;
class Frequency;
class Signal;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    GLobj *globj;
    Signal *signal;
	Frequency *frequency;

private slots:
    void loadFile();
    void undo();
    void about();

private:
    void createActions();
    void createMenus();
    void createStatusBar();
    void createDockWindows();

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *loadAct;
    QAction *undoAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *quitAct;
};

#endif
