#include "raylib.h"
#include "bubble_movement.h"
#include "global.h"
#include "object_animation.h"

/**
 * Checks two items collision on x axis
 * 
 * According to the edges of two items, it checks whether they have
 * collided with each other
 * 
 * @param l_edge_a Left edge on X axis of item A
 * @param r_edge_a Right edge on X axis of item A
 * @param l_edge_b Left edge on X axis of item B
 * @param r_edge_b Right edge on X axis of item B
 **/
bool CheckCollisionX(int* l_edge_a, int* r_edge_a, int* l_edge_b, int* r_edge_b);

/**
 * Checks two items collision on y axis
 * 
 * According to the edges of two items, it checks whether they have
 * collided with each other
 * 
 * @param u_edge_a Upper edge on Y axis of item A
 * @param b_edge_a Bottom edge on Y axis of item A
 * @param u_edge_b Upper edge on Y axis of item B
 * @param b_edge_b Bottom edge on Y axis of item B
 **/
bool CheckCollisionY(int* u_edge_a, int* b_edge_a, int* u_edge_b, int* b_edge_b);

int main(){
    // Circle Coordinates
    int circle_x = 0;
    int circle_y = 0;
    int circle_r = 25;
    int moveSpeed = 1;
    // Circle Edges
    int l_circle_x{circle_x - circle_r};
    int r_circle_x{circle_x + circle_r};
    int b_circle_y{circle_y + circle_r};
    int u_circle_y{circle_y - circle_r};

    // Axe Coordinates
    int axe_x;
    int axe_y;
    int axe_length;
    
    // Create Window
    bool collisionWithAxe = true;
    SetTargetFPS(60);
    InitWindow(windowWidth, windowHeight, "Axe Game");
    InitializeSprite(windowWidth, windowHeight, &axe_x, &axe_y, &axe_length, "axe.png");
    // Axe Edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int b_axe_y{axe_y + axe_length};
    int u_axe_y{axe_y};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        collisionWithAxe = CheckCollisionX(&l_circle_x, &r_circle_x, &l_axe_x, &r_axe_x) && CheckCollisionY(&u_circle_y, &b_circle_y, &u_axe_y, &b_axe_y);
        if(collisionWithAxe)
        {
            DrawText("Game Over!", windowWidth/2, windowHeight/2, 20, RED);
        } 
        else 
        {
            DrawAnimation(axe_x, axe_y);
            DrawCircle(circle_x, circle_y, circle_r, BLUE);
            HandleMovement(&circle_x, &circle_y, moveSpeed);
            // Update Item Objects
            l_circle_x = circle_x - circle_r;
            r_circle_x = circle_x + circle_r;
            b_circle_y = circle_y + circle_r;
            u_circle_y = circle_y - circle_r;
            // Axe Edges
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            b_axe_y = axe_y + axe_length;
            u_axe_y = axe_y;
        }
        EndDrawing();
    }    
}

bool CheckCollisionX(int* l_edge_a, int* r_edge_a, int* l_edge_b, int* r_edge_b)
{
    if((*l_edge_b <= *r_edge_a) && (*r_edge_b >= *l_edge_a))
    {
        return true;
    }
    return false;
}

bool CheckCollisionY(int* u_edge_a, int* b_edge_a, int* u_edge_b, int* b_edge_b)
{
    if((*b_edge_b >= *u_edge_a) && (*u_edge_b <= *b_edge_a))
    {
        return true;
    }
    return false;
}