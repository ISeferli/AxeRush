#ifndef INPUT_H
#define INPUT_H

#include "raylib.h"

/**
 * Bubble Movement
 * 
 * According to the input key, return the position that it showcase
 * 
 * @param position Previous position of the item to move
 * @return Vector2 direction of the input given
 **/
Vector2 HandleMovement(Vector2 position, int width, int height);

#endif