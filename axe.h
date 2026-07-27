#ifndef AXE_H
#define AXE_H

#include <raylib.h>

class Axe{
    private:
        Texture2D texture{LoadTexture("bigger-axe.png")};
        float texWidth{};
        float texHeight{};
        float scale{1.f};
        // Axe Coordinates
        Vector2 position{};
        float speed{1.f};
        Vector2 direction{2, 2};
        float rotation{0};
        float rotationAmount{-5.f};
        float runningRotationTime{};
        float updateRotationTime{1.f/20.f}; // Update time is 1 second in .f, so we have this to run every 10 sec
        float runningSpeedTime{};
        float updateSpeedTime{3.f};
    public:
        Axe(int width, int height);
        Vector2 GetPosition() { return position; }
        void Tick(float deltaTime);
        void MoveAxe();
        void DrawAxe();
        float GetCollisionRadius() { return (texWidth * scale) / 10.f; }
};

#endif