#include <GL/glut.h>
#include "./lib/colors.h"

void setBackgroundRGBA(Color color) {
    glClearColor(
        color.red,
        color.green,
        color.blue,
        color.alpha
    );
    glClear(GL_COLOR_BUFFER_BIT);
}

void setColorRGBA(Color color) {
    glColor4f(
        color.red,
        color.green,
        color.blue,
        color.alpha
    );
}

void setBackgroundColor(ColorName targetColor) {
    Color backgroundColor(targetColor);
    setBackgroundRGBA(backgroundColor);
}

void setColor(ColorName targetColor) {
    Color drawColor(targetColor);
    setColorRGBA(drawColor);
}

void drawTriangle() {
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.9, -0.9, 0.0);
        //glVertex3f(0.9, 0.9, 0.0);
        glVertex3f(0.9, 0.9, 0.0);
        //glVertex3f(0.9, -0.9, 0.0);
        glVertex3f(0.9, -0.9, 0.0);
        //glVertex3f(-0.9, -0.9, 0.0);
    glEnd();
}

void draw() {
    setBackgroundColor(White);
    setColor(Black);
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
