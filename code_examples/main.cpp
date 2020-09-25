#include <GL/glut.h>
#include "../lib/colors.h"
#include "drawSimpleShapes.h"

void draw(GLubyte key, GLint x, GLint y)
{
    switch(key)
    {
        case '1':
            setBackgroundColor(White);
            setDrawColor(Black);
            glutDisplayFunc(drawTriangle);
        break;
        case '2':
            setBackgroundColor(White);
            setDrawColor(Gray);
            glutDisplayFunc(drawSquare);
        break;
        case '3':
            setBackgroundColor(White);
            setDrawColor(Black);
            glutDisplayFunc(drawRhombus);
            break;
        case '4':
            setBackgroundColor(White);
            setDrawColor(Gray);
            glutDisplayFunc(drawCircle);
            break;
    }
    glFlush();
    glutPostRedisplay();
}

void createWindow() {
    GLint width = 800, height = 600;
    glutInitWindowSize(width, height);
    glutCreateWindow("Code Examples");
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    createWindow();
    glutKeyboardFunc(draw);
    glutMainLoop();
    return 0;
}
