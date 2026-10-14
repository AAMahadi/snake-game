#include "../include/food.h"

void loadFood(Food *food, int screenWidth, int screenHeight) {
    float x, y;

    x = rand()%(screenWidth - food->foodSize);
    y = rand()%(screenHeight - food->foodSize);



    food->position.x = (x < (food->foodSize))? (x+food->foodSize): x;
    food->position.y = (y < (food->foodSize))? (y+food->foodSize): y;
}

void drawFood(Food *food) {
    DrawCircle(food->position.x, food->position.y, food->foodSize, RED);
}

bool isFoodEaten(Snake *snake, Food *food) {
    return (CheckCollisionCircleRec(food->position, food->foodSize, 
        (Rectangle){snake->body[0].position.x, snake->body[0].position.y, snake->segmentSize, snake->segmentSize}));
}