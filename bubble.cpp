#include "bubble.h"
#include "global.h"
#include "raymath.h"
#include <iostream>
using namespace std;

Bubble::Bubble()
{ 
    position.x = 0;
    position.y = 10;
}

void Bubble::MoveBubble(Vector2 input)
{
    if(Vector2Length(input)!=0.0)
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(input), speed));
    DrawCircle(position.x, position.y, radius, BLUE);
}

void Bubble::Tick(float deltaTime, Vector2 input)
{
    runningTime += deltaTime;
    if(runningTime >= updateTime){
        speed += 1.f;
        runningTime = 0.f;
    }
    MoveBubble(input);
}