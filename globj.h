/***
*
*    Author:    Kevin Funderburg
*   File: globj.h
*
***/

#ifndef GLobj_H
#define GLobj_H

#include <QtOpenGL/QGLWidget>

class GLobj : public QGLWidget  {
    Q_OBJECT

public:
    GLobj(QWidget *parent = 0);
    ~GLobj();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void paintShapes();
};

#endif
