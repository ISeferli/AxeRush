#ifndef ANIMATION_H
#define ANIMATION_H

/**
 * Object Spritesheet Initialization
 * 
 * Initialize the variables needed to get the 
 * sprites of the object out of the spritesheet
 * 
 * @param width Window width for spritesheet 
 * @param height Window height for spritesheet
 * @param x Objects's x position
 * @param y Objects's y position
 * @param spriteHeight Objects's sprite height
 * @param path Path to the spritesheet
 **/
void InitializeSprite(int width, int height, int* x, int* y, int* spriteHeight, const char* path);

/**
 * Draw sprite
 * 
 * Handle drawing the sprite after initializing it
 * 
 * @param posX Sprite's x position
 * @param posY Sprite's y position
 **/
void DrawAnimation(float posX, float posY);


#endif