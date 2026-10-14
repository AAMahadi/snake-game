#include "../include/snake.h"

int main() {
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

        //updating snakes position
        if(isGoingUp || isGoingDown) {
            if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) snake.direction = (Vector2){snake.segmentSize, 0};
            else if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) snake.direction = (Vector2){(-1)*snake.segmentSize, 0};
        }
        if(isGoingRight || isGoingLeft) {
            if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) snake.direction = (Vector2){0, (-1)*snake.segmentSize};
            else if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) snake.direction = (Vector2){0, snake.segmentSize};
        }
        if(timer >= 0.2) {
            updateSnake(&snake, snake.direction);
            timer = 0;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            //drawing the snake
            drawSnake(&snake);


        EndDrawing();
    }
    CloseWindow();

    return 0;
}