#include "raylib.h"
#include <string>
#include <vector>

class DropList
{
private:
    Rectangle mrect;
    std::vector<std::string> mitems;
    int mind;
    bool mopen;
    float mheight;

public:
    DropList(Vector2 position, float width, float height, const std::vector<std::string>& items)
        : mitems(items), mind(0), mopen(false), mheight(height)
    {
        mrect = {position.x, position.y, width, height};
    }

    void handleEvent()
    {
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mouse, mrect))
            {
                mopen = !mopen;
            }
            else if (mopen)
            {
                bool clickedOnItem = false;
                for (size_t i = 0; i < mitems.size(); ++i)
                {
                    Rectangle itemRect = {mrect.x, mrect.y + mrect.height + i * mheight, mrect.width, mheight};
                    if (CheckCollisionPointRec(mouse, itemRect))
                    {
                        mind = i;
                        mopen = false;
                        clickedOnItem = true;
                        break;
                    }
                }
            }
        }
    }

    void draw() const
    {
        DrawRectangleRec(mrect, LIGHTGRAY);
        DrawRectangleLinesEx(mrect, 2, DARKGRAY);

        std::string mainText = mitems[mind];
        int fontSize = 20;
        Vector2 textSize = MeasureTextEx(GetFontDefault(), mainText.c_str(), fontSize, 1);
        Vector2 textPos = {mrect.x + (mrect.width - textSize.x) / 2, mrect.y + (mrect.height - textSize.y) / 2};
        DrawText(mainText.c_str(), textPos.x, textPos.y, fontSize, BLACK);

        if (mopen)
        {
            for (size_t i = 0; i < mitems.size(); ++i)
            {
                Rectangle itemRect = {mrect.x, mrect.y + mrect.height + i * mheight, mrect.width, mheight};
                if (i == mind)
                    DrawRectangleRec(itemRect, BLUE);
                else
                    DrawRectangleRec(itemRect, WHITE);
                DrawRectangleLinesEx(itemRect, 1, GRAY);

                std::string itemText = mitems[i];
                Vector2 textSize = MeasureTextEx(GetFontDefault(), itemText.c_str(), fontSize, 1);
                Vector2 textPos = {itemRect.x + (itemRect.width - textSize.x) / 2, itemRect.y + (itemRect.height - textSize.y) / 2};
                DrawText(itemText.c_str(), textPos.x, textPos.y, fontSize, BLACK);
            }
        }
    }

    int getSelectedIndex() const {return mind;}
};

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "DropList");
    SetTargetFPS(60);

    std::vector<std::string> items = {"Circle", "Square", "Triangle"}; // Названия на английском, так как raylib не поддерживает русский язык
    DropList dropList({300, 100}, 200, 40, items);

    while (!WindowShouldClose())
    {
        dropList.handleEvent();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        dropList.draw();
        int choice = dropList.getSelectedIndex();
        Vector2 center = {screenWidth / 2, screenHeight / 2 + 100};

        if (choice == 0)
        {
            DrawCircleV(center, 80, BLACK);
        }
        else if (choice == 1)
        {
            DrawRectangleV({center.x - 80, center.y - 80}, {160, 160}, BLACK);
        }
        else if (choice == 2)
        {
            Vector2 p1 = {center.x, center.y - 80};
            Vector2 p2 = {center.x - 80, center.y + 40};
            Vector2 p3 = {center.x + 80, center.y + 40};
            DrawTriangle(p1, p2, p3, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();
}