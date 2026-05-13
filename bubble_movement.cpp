#include "bubble_movement.h"
#include "raylib.h"
#include "global.h"

void HandleMovement(int* x, int* y, int speed)
{
    if(IsKeyDown(KEY_A) && *x > 0)
    {
        *x -= speed;
    }

    if(IsKeyDown(KEY_D) && *x < windowWidth)
    {
        *x += speed;
    }

    if(IsKeyDown(KEY_W) && *y > 0)
    {
        *y -= speed;
    }

    if(IsKeyDown(KEY_S) && *y < windowHeight)
    {
        *y += speed;
    }
}