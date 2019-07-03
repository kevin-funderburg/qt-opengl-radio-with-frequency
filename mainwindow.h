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
class QMenu;

class GLobj;
class Frequency;
class Fractal;
class Signal;
class Radio;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    GLobj *globj;
    Signal *signal;
	Fractal *fractal;
	Frequency *frequency;
	Radio *radio;

private slots:
    void loadFile();
    void about();
	void updateFreq(int);
	void updateVol(int);

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
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *quitAct;
};

#endif
