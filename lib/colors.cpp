#include "colors.h"

Color::Color(ColorName color) {
    changeColor(color);
}

void Color::changeColor(ColorName color) {
    switch (color) {
        case Black:
            red = 0.0;
            green = 0.0;
            blue = 0.0;
            alpha = 1.0;
        break;
        case Blue:
            red = 0.0;
            green = 0.0;
            blue = 0.8;
            alpha = 1.0;
        break;
        case Gray:
            red = 0.5;
            green = 0.5;
            blue = 0.5;
            alpha = 1.0;
        break;
        case Green:
            red = 0.0;
            green = 0.8;
            blue = 0.0;
            alpha = 1.0;
        break;
        case Pink:
            red = 1;
            green = 0.0;
            blue = 0.49;
            alpha = 1.0;
        break;
        case Purple:
            red = 0.4;
            green = 0.0;
            blue = 0.4;
            alpha = 1.0;
        break;
        case Red:
            red = 0.8;
            green = 0.0;
            blue = 0.0;
            alpha = 1.0;
        break;
        case White:
            red = 0.98;
            green = 0.98;
            blue = 0.98;
            alpha = 1.0;
        break;
        default:
            red = 1.0;
            green = 0.0;
            blue = 0.0;
            alpha = 1.0;
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