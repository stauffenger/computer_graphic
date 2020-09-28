#include <GL/glut.h>
#include "drawSimpleShapes.h"
#include <math.h>
#define MAXIMUM 0.9
#define MIDDLE 0.0
#define MINIMUM -0.9
#define RADIUS 0.9
#define TOTAL_SEGMENTS 360.0

void drawTriangle() {
    glBegin(GL_TRIANGLES);
        glVertex2f(MINIMUM, MINIMUM);
        glVertex2f(MAXIMUM, MAXIMUM);
        glVertex2f(MAXIMUM, MINIMUM);
    glEnd();
    glFinish();
}

void calculateWidthAndHeightProportion(GLfloat *widthProportion, GLfloat *heightProportion) {
    GLfloat screenHeight = GLfloat(glutGet(GLUT_WINDOW_HEIGHT));
    GLfloat screenWidth = GLfloat(glutGet(GLUT_WINDOW_WIDTH));
    *widthProportion = *heightProportion = 1;
    if(screenHeight < screenWidth) {
        *widthProportion = screenHeight / screenWidth;
    } else if(screenWidth < screenHeight) {
        *heightProportion = screenWidth / screenHeight;
    }
}

void drawSquare() {
    glBegin(GL_QUADS);
        GLfloat widthProportion, heightProportion;
        calculateWidthAndHeightProportion(&widthProportion, &heightProportion);
        glVertex2f(MINIMUM * widthProportion, MINIMUM * heightProportion);
        glVertex2f(MINIMUM * widthProportion, MAXIMUM * heightProportion);
        glVertex2f(MAXIMUM * widthProportion, MAXIMUM * heightProportion);
        glVertex2f(MAXIMUM * widthProportion, MINIMUM * heightProportion);
    glEnd();
    glFinish();
}

void drawRhombus() {
    glBegin(GL_QUADS);
        glVertex2f(MINIMUM, MIDDLE);
        glVertex2f(MIDDLE, MAXIMUM);
        glVertex2f(MAXIMUM, MIDDLE);
        glVertex2f(MIDDLE, MINIMUM);
    glEnd();
    glFinish();
}

void calculateCurrentPointsXYUsingAngle(GLfloat *x, GLfloat *y, GLfloat angle) {
    GLfloat screenHeight = GLfloat(glutGet(GLUT_WINDOW_HEIGHT));
    GLfloat screenWidth = GLfloat(glutGet(GLUT_WINDOW_WIDTH));
    GLfloat screenProportion;
    if (screenHeight == screenWidth) {
        *x = RADIUS * cosf(angle);
        *y = RADIUS * sinf(angle);
    } else if(screenHeight < screenWidth) {
        screenProportion = screenHeight / screenWidth;
        *x = RADIUS * screenProportion * cosf(angle);
        *y = RADIUS * sinf(angle);
    } else {
        screenProportion = screenWidth / screenHeight;
        *x = RADIUS * cosf(angle);
        *y = RADIUS * screenProportion * sinf(angle);
    }
}

void drawCircle() {
    glBegin(GL_POLYGON);
        for(GLint currentSegment = 0; currentSegment < TOTAL_SEGMENTS; currentSegment++) {
            GLfloat currentAngle = 2.0 * M_PI * GLfloat(currentSegment) / TOTAL_SEGMENTS;
            GLfloat x, y;
            calculateCurrentPointsXYUsingAngle(&x, &y, currentAngle);
            glVertex2f(x, y);
        }
    glEnd();
    glFinish();
}