#include "../include/snake.h"

void drawSnake(Snake *snake) {
    for(int i = 0; i < snake->currentLength; i++) {
        if(i != 0) {
            snake->body[i].position = (Vector2){snake->body[i-1].position.x, snake->body[i-1].position.y + snake->segmentSize};
        }
        
        //eyes
        DrawCircle(snake->leftEyePos.x, snake->leftEyePos.y, 1.5, WHITE);
        DrawCircle(snake->rightEyePos.x, snake->rightEyePos.y, 1.5, WHITE);
        //segments
        DrawRectangle(snake->body[i].position.x, snake->body[i].position.y, snake->segmentSize, snake->segmentSize, GREEN);
        DrawRectangleLines(snake->body[i].position.x, snake->body[i].position.y, snake->segmentSize, snake->segmentSize, DARKGREEN);
    }
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

    if(direction.x == -1 && direction.y == 0) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+6, snake->body[0].position.y+11};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+6, snake->body[0].position.y+3};
    }
    else if(direction.x == 1 && direction.y == 0) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+9, snake->body[0].position.y+11};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+9, snake->body[0].position.y+3};
    }
    else if(direction.x == 0 && direction.y == -1) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+3, snake->body[0].position.y+4};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+11, snake->body[0].position.y+4};
    }
    else if(direction.x == 0 && direction.y == 1) {
        snake->leftEyePos = (Vector2){snake->body[0].position.x+3, snake->body[0].position.y+10};
        snake->rightEyePos = (Vector2){snake->body[0].position.x+11, snake->body[0].position.y+10};
    }
}

