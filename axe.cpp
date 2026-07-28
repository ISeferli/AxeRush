#include "axe.h"
#include "raymath.h"
#include <ctime>

Axe::Axe(int width, int height)
{ 
    srand(time(0));
    position.x = rand() % width;
    position.y = rand() % height;
    texWidth = texture.width;
    texHeight = texture.height;
}

void Axe::Tick(float deltaTime, int width, int height)
{
    runningRotationTime += deltaTime;
    if(runningRotationTime >= updateRotationTime){
        rotation += rotationAmount;
        if(rotation >= 360) rotation = 0;
        runningRotationTime = 0.f;
    }

    runningSpeedTime += deltaTime;
    if(runningSpeedTime >= updateSpeedTime){
        speed += 0.5f;
        runningSpeedTime = 0.f;
    }
    MoveAxe(width, height);
}

void Axe::MoveAxe(int width, int height)
{
    position.y += direction.y * speed;
    position.x += direction.x * speed;
    if(position.y > height || position.y < 0) direction.y = -direction.y;
    if(position.x > width || position.x < 0) direction.x = -direction.x;
    DrawAxe();
}

void Axe::DrawAxe()
{
    Rectangle source{0.f, 0.f, static_cast<float>(texWidth), static_cast<float>(texHeight)};
    Rectangle dest{position.x, position.y, texWidth*scale, texHeight*scale};
    Vector2 origin{(texWidth * scale) / 2.f, (texHeight * scale) / 2.f};
    DrawTexturePro(texture, source, dest, origin, rotation, WHITE);
    // DrawCircleLines(GetPosition().x, GetPosition().y, GetCollisionRadius(), RED);
}