#include <GL/glut.h>
#include "../lib/colors.h"
#include "drawSimpleShapes.h"

void brazilFlag() {
    setDrawColor(Green);
    GLfloat rectangleWidth = 1.8, rectangleHeight = 1.8;
    drawRectangle(rectangleWidth, rectangleHeight);
    
    setDrawColor(Yellow);
    GLfloat rhombusWidth = 1.6, rhombusHeight = 1.6;
    drawRhombus(rhombusWidth, rhombusHeight);
    
    setDrawColor(Blue);
    GLfloat radius = 0.55;
    drawCircle(radius);
}

void triangle() {
    setDrawColor(Blue);
    GLfloat base = 1.8, height = 0.9;
    drawTriangle(base, height);
}

void square() {
    setDrawColor(Purple);
    GLfloat side = 1.8;
    drawSquare(side);
}

void rhombus() {
    setDrawColor(Green);
    GLfloat width = 1.8, height = 1.8;
    drawRhombus(width, height);
}

void circle() {
    setDrawColor(Red);
    GLfloat radius = 0.8;
    drawCircle(radius);
}

void draw(GLubyte key, GLint x, GLint y)
{
    setBackgroundColor(White);
    switch(key)
    {
        case '1':
            glutDisplayFunc(triangle);
        break;
        case '2':
            glutDisplayFunc(square);
        break;
        case '3':
            glutDisplayFunc(rhombus);
        break;
        case '4':
            glutDisplayFunc(circle);
        break;
        case '5':
            glutDisplayFunc(brazilFlag);
        break;
        case 'q':
            exit(0);
        break;
    }
    glFlush();
    glutPostRedisplay();
}

void createWindow() {
    GLint width = 800, height = 600;
    glutInitWindowSize(width, height);
    glutCreateWindow("Code Examples");
    setBackgroundColor(White);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    createWindow();
    glutKeyboardFunc(draw);
    glutMainLoop();
    return 0;
}
