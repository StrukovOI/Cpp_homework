#include <raylib.h>
#include <cmath>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    Vector2 pos = {400, 300};
    float rad = 50;
    float speed = 300;
    Color color = WHITE;

    InitWindow(screenWidth, screenHeight, "Circle");

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT)) pos.x += speed * dt;
        if (IsKeyDown(KEY_LEFT))  pos.x -= speed * dt;
        if (IsKeyDown(KEY_DOWN))  pos.y += speed * dt;
        if (IsKeyDown(KEY_UP))    pos.y -= speed * dt;

        pos.x = fmax(rad, fmin(pos.x, screenWidth - rad));
        pos.y = fmax(rad, fmin(pos.y, screenHeight - rad));

        if (IsKeyPressed(KEY_SPACE))
        {
            color = (Color){(unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), 255};
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(pos, rad, color);
        EndDrawing();
    }

    CloseWindow();
}