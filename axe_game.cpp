#include "raylib.h"
#include "bubble.h"
#include "input.h"
#include "global.h"
#include "axe.h"

int main(){
    // Create Window
    SetTargetFPS(60);
    InitWindow(windowWidth, windowHeight, "Axe Game");

    Bubble bubble{};
    Axe axe{windowWidth, windowHeight};
    Vector2 moveInput{};
    bool collisionWithAxe{false};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        collisionWithAxe = CheckCollisionCircles(bubble.GetPosition(), bubble.GetRadius(), axe.GetPosition(), axe.GetCollisionRadius());
        if(collisionWithAxe)
        {
            DrawText("Game Over!", windowWidth/2, windowHeight/2, 20, RED);
        }
        else
        {
            moveInput = HandleMovement(bubble.GetPosition());
            bubble.Tick(GetFrameTime(), moveInput);
            axe.Tick(GetFrameTime());
        }
        EndDrawing();
    }    
}