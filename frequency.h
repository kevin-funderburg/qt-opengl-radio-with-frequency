/***
*
*	Author:	Kevin Funderburg
*	File: frequency.h
*
***/

#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <QtOpenGL/QGLWidget>

class Frequency : public QGLWidget  
{
		Q_OBJECT

	public:
		Frequency(QWidget *parent = 0);
		~Frequency();
		void setFrequency(int);
		void setVolume(int);

	private:
		int f;			// frequency
		int v;			// volume
		double MIN_X;	// minimum x value
		double MAX_X;	// max x value

	protected:
		void initializeGL();
		void resizeGL(int w, int h);
		void draw();
		void paintGL();
};

#endif
