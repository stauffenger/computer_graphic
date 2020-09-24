#include <GL/glut.h>
#include "../lib/colors.h"

void draw() {
    setBackgroundColor(White);
    setDrawColor(Black);

    glFlush();
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
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
