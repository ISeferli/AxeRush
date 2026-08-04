#include "button.h"

Button::Button(int winWidth, int winHeight, int offset, const char* text)
{
    position.x = winWidth/2 - width/2;
    position.y = winHeight/2 - height/2 + offset;
    buttonRec = {position.x, position.y, width, height};
    bText = text;
}

void Button::DrawButton(Color backgroundColor, Color textColor, Font font)
{
    Vector2 mousePos = GetMousePosition();
    Vector2 textSize = MeasureTextEx(font, bText, 30, 0);
    Vector2 textPos = {
        position.x + (width - textSize.x) / 2.f,
        position.y + (height - textSize.y) / 2.f
    };

    isHovered = CheckCollisionPointRec(mousePos, buttonRec);
    if(isHovered)
    {
        DrawRectangleRounded(buttonRec, 0.4f, 8, textColor);
        DrawTextEx(font, bText, {textPos.x, textPos.y}, 30, 0, backgroundColor);
    }
    else
    {
        DrawRectangleRounded(buttonRec, 0.4f, 8, backgroundColor);
        DrawTextEx(font, bText, {textPos.x, textPos.y}, 30, 0, textColor);
    }
}

bool Button::IsClicked()
{
    return isHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}
