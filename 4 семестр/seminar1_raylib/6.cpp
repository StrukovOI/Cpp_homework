#include <raylib.h>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Rectangle");

    Rectangle rect = {300, 250, 200, 100};

    while (!WindowShouldClose())
    {
        Vector2 mousePos = GetMousePosition();
        bool isMouseInside = CheckCollisionPointRec(mousePos, rect);
        Color rectColor;
        if(isMouseInside)
        {
            Color rectColor = RED;
        }
        else
        {
            Color rectColor = GREEN;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(rect, rectColor);
        EndDrawing();
    }
    CloseWindow();
}