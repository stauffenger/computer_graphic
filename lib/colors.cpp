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