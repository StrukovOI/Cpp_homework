#include <raylib.h>
#include <cmath>    // Необходима для тригонометрических функций

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    Vector2 center = {400, 300};
    float orad = 200;
    float crad = 20;
    float speed = 45;
    float angle = 0;
    
    InitWindow(screenWidth, screenHeight, "Circle");

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        angle += speed * dt;
        float rad = angle * DEG2RAD;
        float x = center.x + orad * cos(rad);
        float y = center.y + orad * sin(rad);
        Vector2 pos = {x, y};

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(pos, crad, RED);
        EndDrawing();
    }
    CloseWindow();
}