#include <raylib.h>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Square");

    float sqx = 200.0f;
    float sqy = 200.0f;
    float size = 100.0f;
    Rectangle square = {sqx, sqy, size, size};
    Vector2 point = {0, 0};
    float a = 0;
    float speed = 90;
    
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        a += speed * dt;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectanglePro(square, point, a, RED);
        EndDrawing();
    }
    CloseWindow();
}