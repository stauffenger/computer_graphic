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

void createWindow() {
    GLint width = 800, height = 600;
    glutInitWindowSize(width, height);
    glutCreateWindow("Chemex Coffeemaker");
}

void draw() {
    Color backgroundColor(White);
    setBackgroundRGBA(backgroundColor);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    createWindow();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
