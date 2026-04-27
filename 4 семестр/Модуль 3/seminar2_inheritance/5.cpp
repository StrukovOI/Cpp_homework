#include <raylib.h>
#include <vector>

class Toggle
{
private:
    Rectangle mbounds;
    bool mstat;
    Color moff;
    Color mon;
    Color mbutc;
    float mbutr;
    float mbutoff;

public:
    Toggle(Vector2 position, float width = 60, float height = 30)
        : mbounds{position.x, position.y, width, height},
          mstat(false),
          moff{220, 220, 220, 255},
          mon{150, 255, 150, 255},
          mbutc{255, 255, 255, 255},
          mbutr(height * 0.4),
          mbutoff(4)
    {
    }

    void setPosition(Vector2 pos)
    {
        mbounds.x = pos.x;
        mbounds.y = pos.y;
    }

    bool handleEvent(Vector2 mpos)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mpos, mbounds))
        {
            mstat = !mstat;
            return true;
        }
        return false;
    }

    void draw() const
    {
        Color bcol;
        if (mstat)
            bcol = mon;
        else
            bcol = moff;
        DrawRectangleRounded(mbounds, 1, 0, bcol);

        float butx;
        if (mstat)
        {
            butx = mbounds.x + mbounds.width - mbutr - mbutoff;
        }
        else
        {
            butx = mbounds.x + mbutr + mbutoff;
        }
        float buty = mbounds.y + mbounds.height / 2;
        DrawCircleV({butx, buty}, mbutr, mbutc);
    }
};

int main()
{
    SetTargetFPS(60);
    const int screenWidth = 800;
    const int screenHeight = 600;
    float toggleWidth = 80;
    float toggleHeight = 40;
    std::vector<Toggle> toggles;
    toggles.reserve(10);
    InitWindow(screenWidth, screenHeight, "Toggles");


    for (int i = 0; i < 10; ++i)
    {
        Toggle newToggle(Vector2{(screenWidth - toggleWidth) / 2, 100.0f + i * 50}, toggleWidth, toggleHeight);
        toggles.push_back(newToggle);
    }

    while (!WindowShouldClose())
    {
        if (IsWindowResized())
        {
            float newStartX = (GetScreenWidth() - toggleWidth) / 2;
            float newStartY = GetScreenHeight() / 6;
            for (int i = 0; i < 10; ++i)
            {
                toggles[i].setPosition({newStartX, newStartY + i * 50});
            }
        }

        Vector2 mouse = GetMousePosition();

        for (auto& t : toggles)
        {
            t.handleEvent(mouse);
        }

        BeginDrawing();
        ClearBackground(WHITE);

        for (const auto& t : toggles)
        {
            t.draw();
        }

        EndDrawing();
    }

    CloseWindow();
}