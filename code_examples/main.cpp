#include <GL/glut.h>
#include "../lib/colors.h"
#include "drawSimpleShapes.h"

void draw(GLubyte key, GLint x, GLint y)
{
    setBackgroundColor(White);
    switch(key)
    {
        case '1':
            setDrawColor(Blue);
            glutDisplayFunc(drawTriangle);
        break;
        case '2':
            setDrawColor(Purple);
            glutDisplayFunc(drawSquare);
        break;
        case '3':
            setDrawColor(Green);
            glutDisplayFunc(drawRhombus);
        break;
        case '4':
            setDrawColor(Red);
            glutDisplayFunc(drawCircle);
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
