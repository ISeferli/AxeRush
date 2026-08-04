#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>

class Button{
    private:
        // Button position
        Rectangle buttonRec{};
        Vector2 position{};
        Vector2 textPosition{};
        float width{200.f};
        float height{50.f};
        // Button details
        Color bColor{};
        const char* bText{};
        bool isHovered{false};
    public:
        Button(int winWidth, int winHeight, int offset, const char* text);
        void DrawButton(Color backgroundColor, Color textColor, Font font);
        bool IsClicked();
};

#endif