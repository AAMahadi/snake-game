#include "../include/snake.h"

void initSnake(Snake *snake) {
    //body segments initialization
    for(int i = 2; i <= snake->currentLength; i++) {
        initSnakeSeg(snake, i);
    }

    //eye initialization
    if(snake->direction.x == (-1)*snake->segmentSize && snake->direction.y == 0) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+6, snake->body[0].position.y+11};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+6, snake->body[0].position.y+3};
    }
    else if(snake->direction.x == snake->segmentSize && snake->direction.y == 0) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+9, snake->body[0].position.y+11};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+9, snake->body[0].position.y+3};
    }
    else if(snake->direction.x == 0 && snake->direction.y == (-1)*snake->segmentSize) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+3, snake->body[0].position.y+4};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+11, snake->body[0].position.y+4};
    }
    else if(snake->direction.x == 0 && snake->direction.y == snake->segmentSize) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+3, snake->body[0].position.y+10};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+11, snake->body[0].position.y+10};
    }
}

void initSnakeSeg(Snake *snake, int segNum) {
    Vector2 newdir = snake->direction;
    int i = segNum - 1;

    if((i > 2) && ((snake->body[i-2].position.x == snake->body[i-1].position.x) || (snake->body[i-2].position.y == snake->body[i-1].position.y))) {
        newdir = (Vector2){(snake->body[i-2].position.x - snake->body[i-1].position.x), (snake->body[i-2].position.y - snake->body[i-1].position.y)};
    } 

    //going right
    if(newdir.x == snake->segmentSize && newdir.y == 0) {
        snake->body[i].position.x = snake->body[i-1].position.x - snake->segmentSize;
        snake->body[i].position.y = snake->body[i-1].position.y;
    }
    //going left
    else if(newdir.x == (-1)*snake->segmentSize && newdir.y == 0) {
        snake->body[i].position.x = snake->body[i-1].position.x + snake->segmentSize;
        snake->body[i].position.y = snake->body[i-1].position.y;
    }
    //going up
    else if(newdir.x == 0 && newdir.y == (-1)*snake->segmentSize) {
        snake->body[i].position.x = snake->body[i-1].position.x;
        snake->body[i].position.y = snake->body[i-1].position.y + snake->segmentSize;
    }
    //going down
    else if(newdir.x == 0 && newdir.y == snake->segmentSize) {
        snake->body[i].position.x = snake->body[i-1].position.x;
        snake->body[i].position.y = snake->body[i-1].position.y - snake->segmentSize;
    } 
}

void drawSnake(Snake *snake) {
    for(int i = 0; i < snake->currentLength; i++) {
        //segments
        DrawRectangleRounded((Rectangle){snake->body[i].position.x, 
            snake->body[i].position.y, 
            snake->segmentSize, 
            snake->segmentSize},
            0.3,
            12, 
            GREEN);
        DrawRectangleRoundedLinesEx((Rectangle){snake->body[i].position.x, 
            snake->body[i].position.y, 
            snake->segmentSize, 
            snake->segmentSize},
            0.3f,
            12,
            0.5,
            DARKGREEN);
    }
    //eyes
    DrawCircle(snake->leftEyePos.x, snake->leftEyePos.y, 1.5, WHITE);
    DrawCircle(snake->rightEyePos.x, snake->rightEyePos.y, 1.5, WHITE);
}

void updateSnake(Snake *snake, Vector2 direction) {
    snake->direction = direction;

    Vector2 prevPos = snake->body[0].position;
    Vector2 temp;

    snake->body[0].position.x += direction.x;
    snake->body[0].position.y += direction.y;

    for(int i = 1; i < snake->currentLength; i++) {
        temp = prevPos;
        prevPos = snake->body[i].position;
        snake->body[i].position = temp;
    }

    if(direction.x == (-1)*snake->segmentSize && direction.y == 0) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+6, snake->body[0].position.y+11};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+6, snake->body[0].position.y+3};
    }
    else if(direction.x == snake->segmentSize && direction.y == 0) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+9, snake->body[0].position.y+11};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+9, snake->body[0].position.y+3};
    }
    else if(direction.x == 0 && direction.y == (-1)*snake->segmentSize) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+3, snake->body[0].position.y+4};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+11, snake->body[0].position.y+4};
    }
    else if(direction.x == 0 && direction.y == snake->segmentSize) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+3, snake->body[0].position.y+10};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+11, snake->body[0].position.y+10};
    }
}

bool checkWallOrSelfCollisions(Snake *snake, int screenWidth, int screenHeight) {
    for(int i = 1; i < snake->currentLength; i++) {
        if(CheckCollisionRecs((Rectangle){snake->body[0].position.x, snake->body[0].position.y, snake->segmentSize, snake->segmentSize}, (Rectangle){snake->body[i].position.x, snake->body[i].position.y, snake->segmentSize, snake->segmentSize})) {
            return true;
        }
    }

    if((snake->body[0].position.x) <= 0 || (snake->body[0].position.x+snake->segmentSize) >= screenWidth || (snake->body[0].position.y) <= 0 || (snake->body[0].position.y+snake->segmentSize) >= screenHeight) {
        return true;
    }
    return false;
}