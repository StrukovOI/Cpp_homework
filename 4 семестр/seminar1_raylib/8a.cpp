#include <raylib.h>
#include <cmath>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    Vector2 pos = {400, 300};
    float rad = 50;
    float v = 200;
    InitWindow(screenWidth, screenHeight, "Circle");


    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            Vector2 mpos = GetMousePosition();
            Vector2 dir = {mpos.x - pos.x, mpos.y - pos.y};
            float len = sqrt(dir.x*dir.x + dir.y*dir.y);
            if (len > 0)
            {
                dir.x /= len;
                dir.y /= len;
                pos.x += dir.x * v * dt;
                pos.y += dir.y * v * dt;
            }
        }

        if (pos.x < rad) pos.x = rad;
        if (pos.x > screenWidth - rad) pos.x = screenWidth - rad;
        if (pos.y < rad) pos.y = rad;
        if (pos.y > screenHeight - rad) pos.y = screenHeight - rad;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(pos, rad, RED);
        EndDrawing();
    }
    CloseWindow();
}