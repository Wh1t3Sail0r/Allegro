#include "color.h"

using namespace std;

// Red
uint32_t red = 0xFFFF0000;

// Orange
uint32_t orange = 0xFFFFA500;

// Yellow
uint32_t yellow = 0xFFFFFF00;

// Green
uint32_t green = 0xFF00FF00;

// Blue
uint32_t blue = 0xFF0000FF;

// Purple
uint32_t purple = 0xFFFF00FF;

// Pink
uint32_t pink = 0xFFFFC0CB;

// Black
uint32_t black = 0xFF000000;

// White
uint32_t white = 0xFFFFFFFF;

// Gray
uint32_t gray = 0xFF606060;

uint32_t string_to_color(string color) {
    transform(color.begin(), color.end(), color.begin(), ::tolower);
    if(color == "red") {
        return red;
    }
    if(color == "orange") {
        return orange;
    }
    if(color == "yellow") {
        return yellow;
    }
    if(color == "green") {
        return green;
    }
    if(color == "blue") {
        return blue;
    }
    if(color == "purple") {
        return purple;
    }
    if(color == "pink") {
        return pink;
    }
    if(color == "black") {
        return black;
    }
    if(color == "white") {
        return white;
    }
    if(color == "gray") {
        return gray;
    }
    return white;
}
