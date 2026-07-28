#include "bubble.h"
#include "raymath.h"
#include <iostream>
using namespace std;

Bubble::Bubble()
{ 
    position.x = 0;
    position.y = 10;
    texWidth = texture.width;
    texHeight = texture.height;
}

void Bubble::MoveBubble(Vector2 input)
{
    if(Vector2Length(input)!=0.0)
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(input), speed));
    
    if(isBroken)
        texture = broken_tex;
    Rectangle source{0.f, 0.f, static_cast<float>(texWidth), static_cast<float>(texHeight)};
    Rectangle dest{position.x, position.y, texWidth*scale, texHeight*scale};
    Vector2 origin{(texWidth * scale) / 2.f, (texHeight * scale) / 2.f};
    DrawTexturePro(texture, source, dest, origin, rotation, WHITE);
}

void Bubble::Tick(float deltaTime, Vector2 input)
{
    runningSpeedTime += deltaTime;
    if(runningSpeedTime >= updateSpeedTime){
        speed += 1.f;
        runningSpeedTime = 0.f;
        rotation = -rotation;
    }

    runningRotationTime += deltaTime;
    if(runningRotationTime >= updateRotationTime){
        rotation = -rotation;
        runningRotationTime = 0.f;
    }
    MoveBubble(input);
}