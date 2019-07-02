/***
*
*	Author: Kevin Funderburg
*	File: signal.h
*
***/

#ifndef SIGNAL_H
#define SIGNAL_H

#include <QtOpenGL/QGLWidget>

class Signal : public QGLWidget  {
    Q_OBJECT

private:
	int ys[5];
	int MAX_Y;
	int MIN_Y;

public:
    Signal(QWidget *parent = 0);
    ~Signal();
	void setvals(int min, int max, int []);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void draw();
};

#endif
