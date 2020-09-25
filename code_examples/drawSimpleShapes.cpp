#include <GL/glut.h>
#include "drawSimpleShapes.h"
#define MAXIMUM 0.9
#define MIDDLE 0.0
#define MINIMUM -0.9

void drawTriangle() {
    glBegin(GL_TRIANGLES);
        glVertex3f(MINIMUM, MINIMUM, MIDDLE);
        glVertex3f(MAXIMUM, MAXIMUM, MIDDLE);
        glVertex3f(MAXIMUM, MINIMUM, MIDDLE);
    glEnd();
}

void drawSquare() {
    glBegin(GL_QUADS);
        glVertex3f(MINIMUM, MINIMUM, MIDDLE);
        glVertex3f(MINIMUM, MAXIMUM, MIDDLE);
        glVertex3f(MAXIMUM, MAXIMUM, MIDDLE);
        glVertex3f(MAXIMUM, MINIMUM, MIDDLE);
    glEnd();
}

void drawRhombus() {
    glBegin(GL_QUADS);
        glVertex3f(MINIMUM, MIDDLE, MIDDLE);
        glVertex3f(MIDDLE, MAXIMUM, MIDDLE);
        glVertex3f(MAXIMUM, MIDDLE, MIDDLE);
        glVertex3f(MIDDLE, MINIMUM, MIDDLE);
    glEnd();
}

void drawCircle() {

}