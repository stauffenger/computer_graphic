#include "colors.h"

Color::Color(ColorName color) {
    changeColor(color);
}

void Color::changeColor(ColorName color) {
    switch (color) {
        case White:
            red = green = blue = 0.98;
            alpha = 1;
            break;
        case Black:
            red = green = blue = 0;
            alpha = 1;
            break;
        case Gray:
            red = green = blue = 0.5;
            alpha = 1;
            break;
        default:
            red = 1;
            green = blue = 0;
            alpha = 1;
            break;
    }
}

void setBackgroundRGBA(Color color) {
    glClearColor(
        color.red,
        color.green,
        color.blue,
        color.alpha
    );
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();
}

void setColorRGBA(Color color) {
    glColor4f(
        color.red,
        color.green,
        color.blue,
        color.alpha
    );
    glFinish();
}

void setBackgroundColor(ColorName targetColor) {
    Color backgroundColor(targetColor);
    setBackgroundRGBA(backgroundColor);
}

void setDrawColor(ColorName targetColor) {
    Color drawColor(targetColor);
    setColorRGBA(drawColor);
}