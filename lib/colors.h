#include <GL/glut.h>
#ifndef COLORS_H
#define COLORS_H
enum ColorName { White, Black, Gray };

class Color {
    public:
        GLfloat red, green, blue, alpha;
        Color(ColorName color);
        void changeColor(ColorName color);
};

void setBackgroundRGBA(Color color);
void setColorRGBA(Color color);
void setBackgroundColor(ColorName targetColor);
void setDrawColor(ColorName targetColor);
#endif
