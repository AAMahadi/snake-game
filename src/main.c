#include <time.h>
#include <stdlib.h>

#include "../include/snake.h"
#include "../include/food.h"

int main() {
    srand(time(NULL));

    const int screenWidth = 800;
    const int screenHeight = 550;
    
    //initializing a window
    InitWindow(screenWidth, screenHeight, "Snake Game");

    //creating the snake
    Snake snake = {
        .currentLength = 3,
        .segmentSize = 16,
    };

    snake.direction = (Vector2){0, (-1)*snake.segmentSize};
    //snakes head position and body initialization
    snake.body[0].position = (Vector2){(GetScreenWidth() - snake.segmentSize)/ 2, GetScreenHeight() / 2};
    initSnake(&snake);

    //food
    Food food = {
        .foodSize = 6
    };

    loadFood(&food, GetScreenWidth(), GetScreenHeight());

    //scoring
    int score = 0;

    SetTargetFPS(60);
    
    //timer
    float timer = 0;

    while(!WindowShouldClose()) {
        timer += GetFrameTime();
        //boolean declarations
        bool isGoingUp = (snake.direction.x == 0 &&  snake.direction.y == (-1)*snake.segmentSize);
        bool isGoingDown= (snake.direction.x == 0 &&  snake.direction.y == snake.segmentSize);
        bool isGoingRight = (snake.direction.x == snake.segmentSize &&  snake.direction.y == 0);
        bool isGoingLeft = (snake.direction.x == (-1)*snake.segmentSize &&  snake.direction.y == 0);


        //checking food collisions
        if(isFoodEaten(&snake, &food)) {
            score += 1;
            loadFood(&food, GetScreenWidth(), GetScreenHeight());
            snake.currentLength++;
            initSnakeSeg(&snake, snake.currentLength);
        }

        //updating snakes position
        if(isGoingUp || isGoingDown) {
            if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) snake.direction = (Vector2){snake.segmentSize, 0};
            else if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) snake.direction = (Vector2){(-1)*snake.segmentSize, 0};
        }
        else if(isGoingRight || isGoingLeft) {
            if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) snake.direction = (Vector2){0, (-1)*snake.segmentSize};
            else if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) snake.direction = (Vector2){0, snake.segmentSize};
        }
        if(timer >= 0.2) {
            updateSnake(&snake, snake.direction);
            timer = 0;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            //drawing food
            drawFood(&food);
            //drawing the snake
            drawSnake(&snake);
            //showing score
            DrawText(TextFormat("Score: %d", score), 15, 15, 30, WHITE);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}