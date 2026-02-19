#include <raylib.h>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    int circles = 100;
    float x[circles];
    float y[circles];
    Color color[circles];
    int num = 0;
    float rad = 20;

    InitWindow(screenWidth, screenHeight, "Circles");

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (num < circles)
            {
                Vector2 mouse = GetMousePosition();
                x[num] = mouse.x;
                y[num] = mouse.y;
                color[num] = RED;
                ++num;
            }
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            for (int i = 0; i < num; ++i)
            {
                color[i] = {(unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), 255};
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < num; ++i)
        {
            DrawCircleV({x[i], y[i]}, rad, color[i]);
        }

        EndDrawing();
    }
    CloseWindow();
}