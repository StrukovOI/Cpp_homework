#include "raylib.h"
#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <iostream>
#include "button.hpp"

float getRandomFloat(float min, float max)
{
    return GetRandomValue(0, 10000) / 10000.0f * (max - min) + min;
}

int getRandomInt(int min, int max)
{
    return GetRandomValue(min, max);
}

Color getRandomColor()
{
    return {(unsigned char)GetRandomValue(0, 255), 
            (unsigned char)GetRandomValue(0, 255), 
            (unsigned char)GetRandomValue(0, 255), 
            255};
}

struct Shape
{
    virtual void draw() = 0;
    virtual void rotate(float a) = 0;
    virtual void setPosition(Vector2 p) = 0;
    virtual Vector2 getPosition() const = 0;
    virtual Vector2 getSize() = 0;
    virtual void setColor(Color c) = 0;
    virtual Color getColor() const = 0;
    virtual ~Shape() = default;
};

class RectangleShape : public Shape
{
private:
    Vector2 mPosition;
    Vector2 mSize;
    float mRotation {0};
    Color mColor;

public:
    RectangleShape(Vector2 size) : mSize(size) {}

    void draw() override
    {
        DrawRectanglePro({mPosition.x, mPosition.y, mSize.x, mSize.y}, {mSize.x / 2, mSize.y / 2}, mRotation, mColor);
    }

    void rotate(float a) override
    {
        mRotation += a;
    }

    void setPosition(Vector2 p) override
    {
        mPosition = p;
    }

    Vector2 getPosition() const override { return mPosition; }

    Vector2 getSize() override
    {
        return mSize;
    }

    void setColor(Color c) override
    {
        mColor = c;
    }

    Color getColor() const override { return mColor; }
};

class CircleShape : public Shape
{
private:
    Vector2 mPosition;
    float mRadius;
    float mRotation {0};
    Color mColor;
    int mSegments;

public:
    CircleShape(float r, int seg = 32) : mRadius(r), mSegments(seg) {}

    void draw() override
    {
        DrawCircleV(mPosition, mRadius, mColor);
    }

    void rotate(float a) override
    {
        mRotation += a;
    }

    void setPosition(Vector2 p) override
    {
        mPosition = p;
    }

    Vector2 getPosition() const override { return mPosition; }

    Vector2 getSize() override
    {
        return {mRadius * 2, mRadius * 2};
    }

    void setColor(Color c) override
    {
        mColor = c;
    }

    Color getColor() const override { return mColor; }
};

class ShapePool
{
private:
    Rectangle mField;
    std::vector<Shape*> mShapes;

public:
    ShapePool(Vector2 position, Vector2 size)
    {
        mField = {position.x, position.y, size.x, size.y};
    }

    void addShape(Shape* p)
    {
        Vector2 size = p->getSize();
        Vector2 min = {size.x / 2, size.y / 2};
        Vector2 max = {mField.width - size.x / 2, mField.height - size.y / 2};
        Vector2 pos = {mField.x + getRandomFloat(min.x, max.x), mField.y + getRandomFloat(min.y, max.y)};
        p->setPosition(pos);
        p->setColor(getRandomColor());
        mShapes.push_back(p);
    }

    size_t getNumbeorOfShapes() const
    {
        return mShapes.size();
    }

    Vector2 getPosition() const
    {
        return {mField.x, mField.y};
    }

    Vector2 getSize() const
    {
        return {mField.width, mField.height};
    }

    Shape& getShape(int index)
    {
        return *mShapes.at(index);
    }

    void deleteAll()
    {
        mShapes.clear();
    }

    void draw() const
    {
        for (auto p : mShapes)
        {
            p->draw();
        }
        DrawRectangleRec(mField, {0, 100, 200, 40});
    }

    void restoreShape(Shape* p)
    {
        mShapes.push_back(p);
    }

    ~ShapePool()
    {
        for (auto p : mShapes)
        {
            delete p;
        }
    }
};

class Command
{
public:
    virtual void execute() = 0;
    virtual void unexecute() = 0;
    virtual ~Command() {}
};

class NoCommand : public Command
{
public:
    void execute() override
    {
    }
    void unexecute() override {}
};

class RotateCommand : public Command
{
private:
    ShapePool& mPool;
    size_t mIndex;
    float mAngle;

public:
    RotateCommand(ShapePool& pool, size_t index, float angle) : mPool(pool), mIndex(index), mAngle(angle) {}

    void execute() override
    {
        mPool.getShape(mIndex).rotate(mAngle);
    }

    void unexecute() override
    {
        mPool.getShape(mIndex).rotate(-mAngle);
    }
};

class RandomColorCommand : public Command
{
private:
    ShapePool& mPool;
    size_t mIndex;
    Color mOld;

public:
    RandomColorCommand(ShapePool& pool, size_t index) : mPool(pool), mIndex(index) {}

    void execute() override
    {
        mOld = mPool.getShape(mIndex).getColor();
        mPool.getShape(mIndex).setColor(getRandomColor());
    }

    void unexecute() override
    {
        mPool.getShape(mIndex).setColor(mOld);
    }
};

class RandomAllPositionsCommand : public Command
{
private:
    ShapePool& mPool;
    std::vector<Vector2> mOldPos;

public:
    RandomAllPositionsCommand(ShapePool& pool) : mPool(pool) {}

    void execute() override
    {
        mOldPos.clear();
        for (size_t i = 0; i < mPool.getNumbeorOfShapes(); ++i)
        {
            Shape& shape = mPool.getShape(i);
            mOldPos.push_back(shape.getPosition());
            Vector2 size = shape.getSize();
            Vector2 min = {size.x / 2, size.y / 2};
            Vector2 max = {mPool.getSize().x - size.x / 2, mPool.getSize().y - size.y / 2};
            Vector2 pos = {mPool.getPosition().x + getRandomFloat(min.x, max.x), mPool.getPosition().y + getRandomFloat(min.y, max.y)};
            shape.setPosition(pos);
        }
    }

    void unexecute() override
    {
        for (size_t i = 0; i < mOldPos.size() && i < mPool.getNumbeorOfShapes(); ++i)
        {
            mPool.getShape(i).setPosition(mOldPos[i]);
        }
    }
};

class AddNewRandomShape : public Command
{
private:
    ShapePool& mPool;
    float mMinSize;
    float mMaxSize;

public:
    AddNewRandomShape(ShapePool& pool, float minSize, float maxSize) : mPool(pool), mMinSize(minSize), mMaxSize(maxSize) {}

    void execute() override
    {
        int r = getRandomInt(0, 2);
        Shape* ps;
        if (r == 0)
        {
            ps = new RectangleShape({getRandomFloat(mMinSize, mMaxSize), getRandomFloat(mMinSize, mMaxSize)});
        }
        else if (r == 1)
        {
            ps = new CircleShape(getRandomFloat(mMinSize / 2, mMaxSize / 2));
        }
        else
        {
            ps = new CircleShape(getRandomFloat(mMinSize / 2, mMaxSize / 2), 3);
        }
        ps->setColor(getRandomColor());
        ps->rotate(getRandomFloat(0, 360));
        Vector2 size = ps->getSize();
        Vector2 pos = {mPool.getPosition().x + getRandomFloat(0, mPool.getSize().x - size.x), mPool.getPosition().y + getRandomFloat(0, mPool.getSize().y - size.y)};
        ps->setPosition(pos);
        mPool.addShape(ps);
    }

    void unexecute() override
    {
        if (mPool.getNumbeorOfShapes() > 0)
        {
            delete &mPool.getShape(mPool.getNumbeorOfShapes() - 1);
        }
    }
};


class ControlPanel
{
private:
    std::vector<Button*> mButtons;
    std::vector<Command*> mCommands;
    std::vector<Command*> mHistory;

public:
    void addButton(Button* p)
    {
        mButtons.push_back(p);
        mCommands.push_back(new NoCommand);
    }

    void addButton(Button* pb, Command* pc)
    {
        mButtons.push_back(pb);
        mCommands.push_back(pc);
    }

    void draw()
    {
        for (auto p : mButtons)
        {
            p->draw();
        }
    }

    void update()
    {
        for (size_t i = 0; i < mButtons.size(); ++i)
        {
            if (mButtons[i]->handle())
            {
                mCommands[i]->execute();
                mHistory.push_back(mCommands[i]);
            }
        }
    }

    void undo()
    {
        if (!mHistory.empty())
        {
            Command* last = mHistory.back();
            mHistory.pop_back();
            last->unexecute();
        }
    }

    ~ControlPanel()
    {
        for (auto p : mButtons)
        {
            delete p;
        }
        for (auto p : mCommands)
        {
            delete p;
        }
    }
};


class RandAllColCmd : public Command
{
private:
    ShapePool& mPool;
    std::vector<Color> mOld;
public:
    RandAllColCmd(ShapePool& pool) : mPool(pool) {}

    void execute() override
    {
        mOld.clear();
        for (size_t i = 0; i < mPool.getNumbeorOfShapes(); ++i)
        {
            mOld.push_back(mPool.getShape(i).getColor());
            mPool.getShape(i).setColor(getRandomColor());
        }
    }

    void unexecute() override
    {
        for (size_t i = 0; i < mOld.size() && i < mPool.getNumbeorOfShapes(); ++i)
        {
            mPool.getShape(i).setColor(mOld[i]);
        }
    }
};

class DelAllCmd : public Command
{
private:
    ShapePool& mPool;
    std::vector<Shape*> mSaved;
public:
    DelAllCmd(ShapePool& pool) : mPool(pool) {}

    void execute() override
    {
        mSaved.clear();
        for (size_t i = 0; i < mPool.getNumbeorOfShapes(); ++i)
            mSaved.push_back(&mPool.getShape(i));
        mPool.deleteAll();
    }

    void unexecute() override
    {
        for (size_t i = 0; i < mSaved.size(); ++i)
        {
            mPool.restoreShape(mSaved[i]);
        }
        mSaved.clear();
    }
};

class UndoCmd : public Command
{
private:
    ControlPanel& mCtrl;
public:
    UndoCmd(ControlPanel& ctrl) : mCtrl(ctrl) {}
    void execute() override { mCtrl.undo(); }
    void unexecute() override {}
};

int main()
{
    InitWindow(800, 800, "Buttons");
    SetTargetFPS(60);

    ShapePool pool({300, 50}, {450, 700});

    pool.addShape(new RectangleShape({getRandomFloat(50, 150), getRandomFloat(50, 150)}));
    pool.addShape(new RectangleShape({getRandomFloat(50, 150), getRandomFloat(50, 150)}));
    pool.addShape(new CircleShape(getRandomFloat(30, 100), 3));
    pool.addShape(new CircleShape(getRandomFloat(30, 100)));
    pool.addShape(new CircleShape(getRandomFloat(30, 100)));

    ControlPanel control;

    control.addButton(new Button({40, 80, 240, 40}, "Rotate First"), new RotateCommand(pool, 0, 30));
    control.addButton(new Button({40, 140, 240, 40}, "Rotate Second"), new RotateCommand(pool, 1, 45));
    control.addButton(new Button({40, 200, 240, 40}, "One Random Color"), new RandomColorCommand(pool, 3));
    control.addButton(new Button({40, 260, 240, 40}, "All Random Positions"), new RandomAllPositionsCommand(pool));
    control.addButton(new Button({40, 320, 240, 40}, "New Random Shape"), new AddNewRandomShape(pool, 10, 150));
    control.addButton(new Button({40, 380, 240, 40}, "no"));    
    control.addButton(new Button({40, 440, 240, 40}, "Rand All Colors"), new RandAllColCmd(pool));
    
    control.addButton(new Button({40, 500, 240, 40}, "Delete All"), new DelAllCmd(pool));
    control.addButton(new Button({40, 560, 240, 40}, "UNDO"), new UndoCmd(control));
    control.addButton(new Button({40, 700, 240, 40}, "Undo"));

    while (!WindowShouldClose())
    {
        control.update();

        BeginDrawing();
        ClearBackground(BLACK);

        pool.draw();
        control.draw();

        EndDrawing();
    }

    CloseWindow();
}