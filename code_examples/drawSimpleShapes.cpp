#include <GL/glut.h>
#include "drawSimpleShapes.h"
#include <math.h>
#define MAXIMUM 1.80
#define MINIMUM -1.80
#define MIDDLE 0.0
#define MAXIMUM_RADIUS 0.90
#define MINIMUM_RADIUS -0.90
#define TOTAL_SEGMENTS 360.0

void toLimitValue(GLfloat *value) {
    if (*value > MAXIMUM) {
        *value = MAXIMUM;
    } else if (*value < MINIMUM) {
        *value = MINIMUM;
    }
}

void drawTriangle(GLfloat base, GLfloat height) {
    toLimitValue(&base);
    toLimitValue(&height);
    GLfloat rightPoint = base/2, leftPoint = -base/2;

    glBegin(GL_TRIANGLES);
        glVertex2f(leftPoint, MIDDLE);
        glVertex2f(MIDDLE, height);
        glVertex2f(rightPoint, MIDDLE);
    glEnd();
    glFinish();
}

void calculateWidthAndHeightProportion(GLfloat *widthProportion, GLfloat *heightProportion) {
    GLfloat height = GLfloat(glutGet(GLUT_WINDOW_HEIGHT));
    GLfloat width = GLfloat(glutGet(GLUT_WINDOW_WIDTH));
    *widthProportion = *heightProportion = 1;
    if(height < width) {
        *widthProportion = height / width;
    } else if(width < height) {
        *heightProportion = width / height;
    }
}

void drawSquare(GLfloat side) {
    toLimitValue(&side);
    GLfloat upperY = side/2, bottomY = -side/2;
    GLfloat rightX = side/2, leftX = -side/2;
    glBegin(GL_QUADS);
        GLfloat widthProportion, heightProportion;
        calculateWidthAndHeightProportion(&widthProportion, &heightProportion);
        glVertex2f(leftX * widthProportion, bottomY * heightProportion);
        glVertex2f(leftX * widthProportion, upperY * heightProportion);
        glVertex2f(rightX * widthProportion, upperY * heightProportion);
        glVertex2f(rightX * widthProportion, bottomY * heightProportion);
    glEnd();
    glFinish();
}

void drawRectangle(GLfloat width, GLfloat height) {
    toLimitValue(&width);
    toLimitValue(&height);
    GLfloat upperY = height/2, bottomY = -height/2;
    GLfloat rightX = width/2, leftX = -width/2;
    glBegin(GL_QUADS);
        glVertex2f(leftX, bottomY);
        glVertex2f(leftX, upperY);
        glVertex2f(rightX, upperY);
        glVertex2f(rightX, bottomY);
    glEnd();
    glFinish();
}

void drawRhombus(GLfloat width, GLfloat height) {
    toLimitValue(&width);
    toLimitValue(&height);
    GLfloat upperY = height/2, bottomY = -height/2;
    GLfloat rightX = width/2, leftX = -width/2;
    glBegin(GL_QUADS);
        glVertex2f(leftX, MIDDLE);
        glVertex2f(MIDDLE, upperY);
        glVertex2f(rightX, MIDDLE);
        glVertex2f(MIDDLE, bottomY);
    glEnd();
    glFinish();
}

void calculateCurrentPointsXYUsingAngle(GLfloat *x, GLfloat *y, GLfloat angle) {
    GLfloat height = GLfloat(glutGet(GLUT_WINDOW_HEIGHT));
    GLfloat width = GLfloat(glutGet(GLUT_WINDOW_WIDTH));
    GLfloat windowProportion;
    if (height == width) {
        *x *= cosf(angle);
        *y *= sinf(angle);
    } else if(height < width) {
        windowProportion = height / width;
        *x *= windowProportion * cosf(angle);
        *y *= sinf(angle);
    } else {
        windowProportion = width / height;
        *x *= cosf(angle);
        *y *= windowProportion * sinf(angle);
    }
}

void toLimitRadius(GLfloat *radius) {
    if (*radius > MAXIMUM_RADIUS) {
        *radius = MAXIMUM_RADIUS;
    } else if(*radius < MINIMUM_RADIUS) {
        *radius = MINIMUM_RADIUS
    }
}

void drawCircle(GLfloat radius) {
    toLimitRadius(&radius);
    glBegin(GL_POLYGON);
        for(GLint currentSegment = 0; currentSegment < TOTAL_SEGMENTS; currentSegment++) {
            GLfloat currentAngle = 2.0 * M_PI * GLfloat(currentSegment) / TOTAL_SEGMENTS;
            GLfloat x = radius, y = radius;
            calculateCurrentPointsXYUsingAngle(&x, &y, currentAngle);
            glVertex2f(x, y);
        }
    glEnd();
    glFinish();
}
