#include "../include/snake.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 550;
    
    //initializing a window
    InitWindow(screenWidth, screenHeight, "Snake Game");

    //creating the snake
    Snake snake = {
        .currentLength = 4,
        .direction = (Vector2){0, 0},
        .segmentSize = 15
    };

    //snakes head position
    snake.body[0].position = (Vector2){GetScreenWidth() / 2, GetScreenHeight() / 2};
    //eyse positions
    snake.leftEyePos = (Vector2){snake.body[0].position.x+6, snake.body[0].position.y+11};
    snake.rightEyePos = (Vector2){snake.body[0].position.x+6, snake.body[0].position.y+2};

    SetTargetFPS(60);
    
    while(!WindowShouldClose()) {
        //updating snakes position

        updateSnake(&snake, (Vector2){0, -1});

        BeginDrawing();
            ClearBackground(BLACK);
            //drawing the snake
            drawSnake(&snake);


        EndDrawing();
    }
    CloseWindow();

    return 0;
}