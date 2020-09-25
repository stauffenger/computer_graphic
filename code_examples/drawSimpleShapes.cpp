#include <GL/glut.h>
#include "drawSimpleShapes.h"

void drawTriangle() {
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.9, -0.9, 0.0);
        glVertex3f(0.9, 0.9, 0.0);
        glVertex3f(0.9, -0.9, 0.0);
    glEnd();
}

void drawSquare() {
    glBegin(GL_QUADS);
        glVertex3f(-0.9, -0.9, 0.0);
        glVertex3f(-0.9, 0.9, 0.0);
        glVertex3f(0.9, 0.9, 0.0);
        glVertex3f(0.9, -0.9, 0.0);
    glEnd();
}

void drawRhombus() {
    glBegin(GL_QUADS);
        glVertex3f(-0.9, 0.0, 0.0);
        glVertex3f(0.0, 0.9, 0.0);
        glVertex3f(0.9, 0.0, 0.0);
        glVertex3f(0.0, -0.9, 0.0);
    glEnd();
}

void drawCircle() {

}