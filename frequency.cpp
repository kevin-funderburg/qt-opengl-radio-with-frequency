/***
*
*   Author: Kevin Funderburg
*   File:   frequency.cpp 
*
***/

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <QDebug>
#include <QtCore/qmath.h>
#include <math.h>

#include "frequency.h"

Frequency::Frequency(QWidget *parent)
    : QGLWidget(parent), 
      f(1), v(0),
      MIN_X(-16 * M_PI),
      MAX_X(16 * M_PI)
{

}

Frequency::~Frequency()
{

}

//Initialize the GL settings
void Frequency::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glLineWidth(2.0);
    glPointSize(2.0);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void Frequency::resizeGL( int w, int h )
{
    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(MIN_X, MAX_X, -7.0, 7.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    //implicit call to paintGL after resized
}


void Frequency::setFrequency(int val)
{
    f = val;
    updateGL();
}

void Frequency::setVolume(int val)
{
    v = val;
    updateGL();
}

void Frequency::draw()
{   
    double y; 
    int count = 0;
    //glOrtho(MIN_X, MAX_X, -7.0, 7.0, -1.0, 1.0);
    glLoadIdentity();
    glBegin(GL_LINE_STRIP);
        for(double x = MIN_X; x < MAX_X; x += 0.1) {
            count++;
            y = double(v) * (cos((2*M_PI) * double(f)/10 * x));
            if (count % 50 == 0) {  // set random color
                float num1 = (float)rand() / RAND_MAX;
                float num2 = (float)rand() / RAND_MAX;
                float num3 = (float)rand() / RAND_MAX;
                glColor3f(num1, num2, num3);
            }
            glVertex2f(x, y);
        }
    glEnd();
}

//Paints the GL scene
void Frequency::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw();
    glFlush ();
}

