#include <raylib.h>
#include <string>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Mouse");

    while (!WindowShouldClose())
    {
        Vector2 mousePos = GetMousePosition();
        Vector2 windowPos = GetWindowPosition();
        Vector2 absPos = {windowPos.x + mousePos.x, windowPos.y + mousePos.y};

        std::string text = "Window: (" + std::to_string((int)mousePos.x) + ", " + std::to_string((int)mousePos.y) + ") "
            "Screen: (" + std::to_string((int)absPos.x) + ", " + std::to_string((int)absPos.y) + ")";

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(text.c_str(), 20, 20, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
}