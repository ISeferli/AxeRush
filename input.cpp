#include "input.h"
#include "global.h"

Vector2 HandleMovement(Vector2 position)
{
    Vector2 direction{};
    if(IsKeyDown(KEY_A) && position.x > 0)
        direction.x -= 1.f;
    if(IsKeyDown(KEY_D) && position.x < windowWidth)
        direction.x += 1.f;
    if(IsKeyDown(KEY_W) && position.y > 0)
        direction.y -= 1.f;
    if(IsKeyDown(KEY_S) && position.y < windowHeight)
        direction.y += 1.f;
    return direction;
}