#include <raylib.h>
#include <cmath>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    Vector2 pos = {400, 300};
    Vector2 v = {0, 0};
    float rad = 20;
    float w = 500;
    float maxSpeed = 400;

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
                v.x += dir.x * w * dt;
                v.y += dir.y * w * dt;
            }
        }

        pos.x += v.x * dt;
        pos.y += v.y * dt;

        if (pos.x < rad)
        {
            pos.x = rad;
            v.x = -v.x;
        }
        if (pos.x > screenWidth - rad)
        {
            pos.x = screenWidth - rad;
            v.x = -v.x;
        }
        if (pos.y < rad)
        {
            pos.y = rad;
            v.y = -v.y;
        }
        if (pos.y > screenHeight - rad)
        {
            pos.y = screenHeight - rad;
            v.y = -v.y;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(pos, rad, RED);
        EndDrawing();
    }
    CloseWindow();
}