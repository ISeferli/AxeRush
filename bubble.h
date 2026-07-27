#ifndef BUBBLE_H
#define BUBBLE_H

#include <raylib.h>

class Bubble{
    private:
        // Circle Coordinates
        Vector2 position{};
        int radius{25};
        float speed{1.f};
        float runningTime{};
        float updateTime{5.f}; // Update time is 1 second in .f, so we have this to run every 5 sec
    public:
        Bubble();
        Vector2 GetPosition() { return position; }
        int GetRadius() { return radius; }
        void Tick(float deltaTime, Vector2 moveInput);
        void MoveBubble(Vector2 input);
};

#endif