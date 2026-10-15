#ifndef SNAKE_H
#define SNAKE_H

#include <raylib.h>

#define MAX_LENGTH 100

typedef struct {
    Vector2 position;
} Segments;

typedef struct {
    Segments body[MAX_LENGTH];
    Vector2 leftEyePos;
    Vector2 rightEyePos;
    int currentLength;
    Vector2 direction;
    float segmentSize;
} Snake;


void drawSnake(Snake *snake);
void updateSnake(Snake *snake, Vector2 direction);
void initSnake(Snake *snake);
void initSnakeSeg(Snake *snake, int segNum);
bool checkWallOrSelfCollisions(Snake *snake, int screenWidth, int screenHeight);


#endif