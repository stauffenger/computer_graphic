#include <GL/glut.h>
#include "./lib/colors.h"

void drawTriangle() {
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.9, -0.9, 0.0);
        glVertex3f(0.9, 0.9, 0.0);
        glVertex3f(0.9, -0.9, 0.0);
    glEnd();
}

void draw() {
    setBackgroundColor(White);
    setDrawColor(Black);
    drawTriangle();

    glFlush();
}

void createWindow() {
    GLint width = 800, height = 600;
    glutInitWindowSize(width, height);
    glutCreateWindow("Chemex Coffeemaker");
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    createWindow();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
