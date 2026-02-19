#include <raylib.h>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    float x = 400;
    float y = 300;
    float rad = 30;
    float speed = 100;

    InitWindow(screenWidth, screenHeight, "Circle");

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        x += speed * dt;

        if (x - rad > screenWidth)
        {
            x = -rad;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV({ x, y }, rad, RED);
        EndDrawing();
    }
    CloseWindow();
}