#include "raylib.h"
#include "bubble.h"
#include "input.h"
#include "axe.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

int main(){
    // Create Window
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Axe Game");

    Bubble bubble{};
    Axe axe{SCREEN_WIDTH, SCREEN_HEIGHT};
    Vector2 moveInput{};
    bool collisionWithAxe{false};
    int brokenTime{2};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        collisionWithAxe = CheckCollisionCircles(bubble.GetPosition(), bubble.GetRadius(), axe.GetPosition(), axe.GetCollisionRadius());
        if(collisionWithAxe)
        {
            if(brokenTime<=0) {
                bubble.BrokeBubble();
                brokenTime -= 1;
                bubble.Tick(GetFrameTime(), moveInput);
            } else
                DrawText("Game Over!", SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 20, RED);
        }
        else
        {
            moveInput = HandleMovement(bubble.GetPosition(), SCREEN_WIDTH, SCREEN_HEIGHT);
            bubble.Tick(GetFrameTime(), moveInput);
            axe.Tick(GetFrameTime(), SCREEN_WIDTH, SCREEN_HEIGHT);
        }
        EndDrawing();
    }    
}