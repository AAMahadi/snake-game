#include <time.h>
#include <stdlib.h>

#include "../include/snake.h"
#include "../include/food.h"

int main() {
    srand(time(NULL));

    const int screenWidth = 800;
    const int screenHeight = 640;
    
    //initializing a window
    InitWindow(screenWidth, screenHeight, "Snake Game");

    //creating the snake
    Snake snake = {
        .currentLength = 3,
        .segmentSize = 16,
    };

    snake.direction = (Vector2){0, (-1)*snake.segmentSize};
    //snakes head position and body initialization
    snake.body[0].position = (Vector2){((screenWidth/snake.segmentSize) / 2) * snake.segmentSize, ((screenHeight/snake.segmentSize) / 2) * snake.segmentSize};
    initSnake(&snake);

    //food
    Food food = {
        .foodSize = 6
    };

    loadFood(&food, GetScreenWidth(), GetScreenHeight());

    //scoring
    int score = 0;

    bool isGameOver = false;

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
            if(snake.currentLength != MAX_LENGTH) {
                snake.currentLength++;
                initSnakeSeg(&snake, snake.currentLength);
            }
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

        //game over checking and snake moving
        if(!isGameOver && timer >= 0.12) {
            updateSnake(&snake, snake.direction);
            timer = 0;

            if(checkWallOrSelfCollisions(&snake, GetScreenWidth(), GetScreenHeight())) {
                isGameOver = true;
            }
        }

        //restart logic
        if(isGameOver && IsKeyPressed(KEY_R)) {
            snake.currentLength = 3;
            snake.segmentSize = 16;
            snake.direction = (Vector2){0, (-1)*snake.segmentSize};
            //snakes head position and body initialization
            snake.body[0].position = (Vector2){((screenWidth/snake.segmentSize) / 2) * snake.segmentSize, ((screenHeight/snake.segmentSize) / 2) * snake.segmentSize};
            initSnake(&snake);

            score = 0;

            isGameOver = false;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            //drawing boundary
            DrawRectangleLines(1, 1, 799, 639, WHITE);
            //drawing food
            drawFood(&food);
            //drawing the snake
            drawSnake(&snake);
            //showing score
            DrawText(TextFormat("Score: %d", score), 15, 15, 30, WHITE);

            if(isGameOver) {
                DrawRectangleRec((Rectangle){0,0, GetScreenWidth(), GetScreenHeight()}, Fade(BLACK, 0.7));
                DrawText("GAME OVER", (GetScreenWidth()-260)/2, 220,40, RED);
                DrawText(TextFormat("Score: %d", score), (GetScreenWidth()-120)/2, 280, 25, WHITE);
                DrawRectangleRounded((Rectangle){(GetScreenWidth()/2 - 110), 340, 220, 50}, 0.3, 12,GREEN);
                DrawText("Press R to Restart", (GetScreenWidth()/2 - 110) + 10, 355, 20, BLACK);
                DrawText("Press ESC to Quit", (GetScreenWidth()/2 - 85) + 20, 395, 15, RAYWHITE);
            }

        EndDrawing();
    }
    CloseWindow();

    return 0;
}