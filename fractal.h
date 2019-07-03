#pragma once
#include <QtOpenGL/QGLWidget>
#include <QTimer>
#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include <stdlib.h> 
#include <time.h> 

class Fractal : public QGLWidget  {
    Q_OBJECT

public:
    Fractal(QWidget *parent = 0);
    ~Fractal();

public slots:
    void draw();

private:
    GLfloat v[3][2];
    int n;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m);
    void triangle(GLfloat *a, GLfloat *b, GLfloat *c);
    void paintGL();
};
