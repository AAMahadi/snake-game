#ifndef FOOD_H
#define FOOD_H

#include <stdlib.h>
#include <raylib.h>
#include "../include/snake.h"

typedef struct {
    Vector2 position;
    int foodSize;
} Food;

void loadFood(Food *food, int screenWidth, int screenHeight);
void drawFood(Food *food);
bool isFoodEaten(Snake *snake, Food *food);

#endif