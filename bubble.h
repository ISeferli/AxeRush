#ifndef BUBBLE_H
#define BUBBLE_H

#include <raylib.h>

class Bubble{
    private:
        bool isBroken{false};
        Texture2D texture{LoadTexture("bubble.png")};
        Texture2D normal_tex{LoadTexture("bubble.png")};
        Texture2D broken_tex{LoadTexture("bubble_break.png")};
        float texWidth{};
        float texHeight{};
        float scale{3.f};
        // Circle Coordinates
        Vector2 position{};
        int radius{25};
        float speed{2.f};
        float rotation{10.f};
        float runningRotationTime{};
        float updateRotationTime{1.f/4.f};
        float runningSpeedTime{};
        float updateSpeedTime{5.f}; // Update time is 1 second in .f, so we have this to run every 5 sec
        int brokenTime{10};
    public:
        Bubble();
        void RestartBubble();
        Vector2 GetPosition() { return position; }
        int GetBrokenTime() { return brokenTime; }
        void SetBrokenTime(int amount) { brokenTime -= amount; }
        void BrokeBubble() { isBroken = true; }
        int GetRadius() { return radius; }
        void Tick(float deltaTime, Vector2 moveInput);
        void MoveBubble(Vector2 input);
};

#endif