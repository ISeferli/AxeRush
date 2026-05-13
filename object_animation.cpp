#include "object_animation.h"
#include "raylib.h"
#include "global.h"

Texture2D axe;
Rectangle axeRec;

void InitializeSprite(int width, int height, int* x, int *y, int* sprHeight, const char* path)
{
    axe = LoadTexture(path);
    axeRec.width = axe.width;
    axeRec.height = axe.height;
    axeRec.x = 0;
    axeRec.y = 0;
    *x = width/2 - axeRec.width/2;
    *y = height - axeRec.height;
    *sprHeight = axeRec.height;
    DrawTextureRec(axe, axeRec, {(float)*x, (float)*y}, WHITE);
}

void DrawAnimation(float posX, float posY)
{
    DrawTextureRec(axe, axeRec, {posX, posY}, WHITE);
}