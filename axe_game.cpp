#include "raylib.h"
#include "bubble.h"
#include "input.h"
#include "axe.h"
#include "button.h"

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 450;
const char* GAME_OVER = "Game Over!";
const char* BACK_MENU = "Press ENTER to RESTART";
const char* TIME = "Time";
const Color yellow{252, 198, 29, 255};
const Color white{247, 247, 247, 255};
const Color brown{197, 149, 96, 255};

enum GameScreen {
    MAIN_MENU,
    GAME
};

void GameLoad(GameScreen *screen) {
    (*screen) = MAIN_MENU;
}

void GameSceneUpdate(Bubble* bubble, Axe* axe, Font gameFont) {
    Vector2 moveInput{};
    if(CheckCollisionCircles(bubble->GetPosition(), bubble->GetRadius(), axe->GetPosition(), axe->GetCollisionRadius()))
    {
        if(bubble->GetBrokenTime()>0) {
            bubble->BrokeBubble();
            bubble->SetBrokenTime(1);
            bubble->Tick(GetFrameTime(), moveInput);
        } else {
            Vector2 char_size = MeasureTextEx(gameFont, GAME_OVER, 60, 5);
            DrawTextEx(gameFont, GAME_OVER, {SCREEN_WIDTH/2 - char_size.x/2, SCREEN_HEIGHT/2 - char_size.y/2}, 60, 5, yellow);
            Vector2 button_size = MeasureTextEx(gameFont, BACK_MENU, 30, 5);
            DrawTextEx(gameFont, BACK_MENU, {SCREEN_WIDTH/2 - button_size.x/2, SCREEN_HEIGHT/2 + 20}, 30, 5, white);
        }

        if(IsKeyPressed(KEY_ENTER)) {
            bubble->RestartBubble();
            axe->RestartAxe(SCREEN_WIDTH, SCREEN_HEIGHT);
        }
    }
    else
    {
        moveInput = HandleMovement(bubble->GetPosition(), SCREEN_WIDTH, SCREEN_HEIGHT);
        bubble->Tick(GetFrameTime(), moveInput);
        axe->Tick(GetFrameTime(), SCREEN_WIDTH, SCREEN_HEIGHT);
    }
    Vector2 timeTextSize = MeasureTextEx(gameFont, TIME, 30, 0);
    DrawTextEx(gameFont, TIME, {SCREEN_WIDTH/2 - timeTextSize.x/2, 0.f + timeTextSize.y/2}, 30, 0, yellow);
}

void MenuSceneUpdate(Font gameFont, GameScreen* screen, bool* exit) {
    Button startButton{SCREEN_WIDTH, SCREEN_HEIGHT, -50, "Start Game"};
    startButton.DrawButton(white, brown, gameFont);
    if(startButton.IsClicked())
        (*screen) = GAME;

    Button exitButton{SCREEN_WIDTH, SCREEN_HEIGHT, 50, "Exit"};
    exitButton.DrawButton(white, brown, gameFont);
    if(exitButton.IsClicked())
        (*exit) = true;
}

int main(){
    // Create Window
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Axe Rush");
    
    GameScreen currentScreen{};
    GameLoad(&currentScreen);

    Texture background{LoadTexture("background.png")};
    Bubble bubble{};
    Axe axe{SCREEN_WIDTH, SCREEN_HEIGHT};
    Font gameFont{LoadFontEx("playlike-font.ttf", 32, nullptr, 0)};
    bool exit = false;
    while (!WindowShouldClose() && exit==false)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(background, {0.f-background.width, 0.f - background.height}, 0.f, 4.f, WHITE);
        switch(currentScreen){
            case MAIN_MENU:
            MenuSceneUpdate(gameFont, &currentScreen, &exit);
            break;
            case GAME:
            HideCursor();
            GameSceneUpdate(&bubble, &axe, gameFont);
            break;
        }
        EndDrawing();
    }   
    UnloadFont(gameFont);
}