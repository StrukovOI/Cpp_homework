#include "raylib.h"
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

class Observer
{
public:
    virtual void update(float value) = 0;
    virtual ~Observer() = default;
};

class Drawable
{
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

class Slider : public Drawable
{
private:
    Rectangle mTrack;
    Rectangle mThumb;
    Color mTrackColor {200, 200, 220, 255};
    Color mThumbColor {150, 150, 240, 255};
    bool mIsPressed {false};
    std::set<Observer*> mObservers;

public:
    Slider(Vector2 center, Vector2 trackSize, Vector2 thumbSize)
    {
        mTrack = {center.x - trackSize.x / 2, center.y - trackSize.y / 2, trackSize.x, trackSize.y};
        mThumb = {center.x - thumbSize.x / 2, center.y - thumbSize.y / 2, thumbSize.x, thumbSize.y};
    }

    void draw() const override
    {
        DrawRectangleRec(mTrack, mTrackColor);
        DrawRectangleRec(mThumb, mThumbColor);
    }

    void updateInput()
    {
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mouse, mThumb) || CheckCollisionPointRec(mouse, mTrack))
            {
                mIsPressed = true;
                mThumb.x = mouse.x - mThumb.width / 2;
                notifyObservers();
            }
        }

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            mIsPressed = false;
        }

        if (mIsPressed)
        {
            float min = mTrack.x;
            float max = mTrack.x + mTrack.width;
            float clampedX = std::clamp(mouse.x, min, max);
            mThumb.x = clampedX - mThumb.width / 2;
            notifyObservers();
        }
    }

    float getValue() const
    {
        float part = (mThumb.x + mThumb.width / 2) - mTrack.x;
        return (part / mTrack.width) * 100.0f;
    }

    void addObserver(Observer* p)
    {
        mObservers.insert(p);
    }

    void notifyObservers()
    {
        for (auto p : mObservers)
        {
            p->update(getValue());
        }
    }
};

class Circle : public Observer, public Drawable
{
protected:
    Vector2 mPosition;
    float mRadius;
    float mScale {1.0f};
    Color mColor {0, 255, 0, 255};

public:
    Circle(Vector2 position, float radius)
        : mPosition(position), mRadius(radius)
    {
    }

    void draw() const override
    {
        DrawCircleV(mPosition, mRadius * mScale, mColor);
    }

    void update(float value) override
    {
        std::cout << value << std::endl;
        mScale = value / 50.0f;
    }
};

class CircleColorChange : public Circle
{
public:
    CircleColorChange(Vector2 position, float radius)
        : Circle(position, radius)
    {
        mColor = {0, 0, 100, 255};
    }

    void update(float value) override
    {
        mColor = {0, 0, (unsigned char)(value * 2), 255};
    }
};

class Square : public Observer, public Drawable
{
private:
    Vector2 mPosition;
    float mSize;
    float mRotation {0.0f};

public:
    Square(Vector2 position, float size)
        : mPosition(position), mSize(size)
    {
    }

    void draw() const override
    {
        DrawRectanglePro({mPosition.x, mPosition.y, mSize, mSize}, {mSize / 2, mSize / 2}, mRotation, RED);
    }

    void update(float value) override
    {
        mRotation = 3 * value;
    }
};



class Obs
{
public:
    virtual void updateC(float v) = 0;
    virtual ~Obs() = default;
};

class Slid : public Drawable
{
private:
    Rectangle mT;
    Rectangle mTh;
    Color mTC {100, 200, 100, 255};
    Color mThC {50, 150, 50, 255};
    bool mP {false};
    std::set<Obs*> mO;

public:
    Slid(Vector2 c, Vector2 ts, Vector2 ths)
    {
        mT = {c.x - ts.x/2, c.y - ts.y/2, ts.x, ts.y};
        mTh = {c.x - ths.x/2, c.y - ths.y/2, ths.x, ths.y};
    }

    void draw() const override
    {
        DrawRectangleRec(mT, mTC);
        DrawRectangleRec(mTh, mThC);
    }

    void updateInput()
    {
        Vector2 m = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(m, mTh) || CheckCollisionPointRec(m, mT))
            {
                mP = true;
                mTh.x = m.x - mTh.width/2;
                notify();
            }
        }
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) mP = false;
        if (mP)
        {
            float min = mT.x, max = mT.x + mT.width;
            float cx = std::clamp(m.x, min, max);
            mTh.x = cx - mTh.width/2;
            notify();
        }
    }

    float getValue() const
    {
        float p = (mTh.x + mTh.width/2) - mT.x;
        return (p / mT.width) * 100.0f;
    }

    void addC(Obs* p) { mO.insert(p); }

    void notify()
    {
        float v = getValue();
        for (auto p : mO) p->updateC(v);
    }
};

class BaseObj : public Observer, public Obs, public Drawable
{
protected:
    Vector2 pos;
    float sz;
    float rot {0};
    Color col {200, 200, 200, 255};

public:
    BaseObj(Vector2 p, float s) : pos(p), sz(s) {}
    virtual void drawShape() const = 0;

    void draw() const override
    {
        DrawRectanglePro({pos.x, pos.y, sz, sz}, {sz/2, sz/2}, rot, col);
        drawShape();
    }

    void update(float v) override { rot = v * 3.6f; }

    void updateC(float v) override
    {
        col.r = (unsigned char)(v * 2.55f);
        col.g = 80;
        col.b = (unsigned char)(255 - v * 2.55f);
    }
};

class CObj : public BaseObj
{
public:
    CObj(Vector2 p, float r) : BaseObj(p, r*2) {}
    void drawShape() const override { DrawCircleV(pos, sz/2, col); }
    void draw() const override { DrawCircleV(pos, sz/2, col); }
};

class SObj : public BaseObj
{
public:
    SObj(Vector2 p, float s) : BaseObj(p, s) {}
    void drawShape() const override {}
};

int main()
{
    InitWindow(800, 800, "Sliders");
    SetTargetFPS(60);

    Slider s1({200, 700}, {300, 20}, {30, 60});
    Slid s2({600, 700}, {300, 20}, {30, 60});

    std::vector<BaseObj*> objs
    {
        new CObj({150, 250}, 40),
        new SObj({400, 250}, 80),
        new SObj({650, 250}, 100)
    };

    for (auto p : objs)
    {
        s1.addObserver(p);
        s2.addC(p);
    }

    while (!WindowShouldClose())
    {
        s1.updateInput();
        s2.updateInput();

        BeginDrawing();
        ClearBackground(BLACK);
        s1.draw();
        s2.draw();

        for (auto p : objs) p->draw();

        DrawText("ROT", 300, 670, 20, WHITE);
        DrawText("COL", 700, 670, 20, WHITE);

        EndDrawing();
    }

    for (auto p : objs) delete p;
    CloseWindow();
    return 0;
}