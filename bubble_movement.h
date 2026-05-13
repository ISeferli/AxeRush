#ifndef MOVEMENT_H
#define MOVEMENT_H

/**
 * Bubble Movement
 * 
 * According to the input key, make the bubble move around the 
 * space it can get to.
 * 
 * @param x Change x in case of horizontal movement input
 * @param y Change y in case of vertical movement input
 * @param speed Number of frames that it takes to go from one place
 * to another
 **/
void HandleMovement(int* x, int* y, int speed);

#endif