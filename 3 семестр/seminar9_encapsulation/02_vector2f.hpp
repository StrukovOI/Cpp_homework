#pragma once
#include <cmath>
#include <iostream>

struct Vector2f 
{
    float x;
    float y;
};

Vector2f operator+(Vector2f a, Vector2f b) 
{
    Vector2f result = {a.x + b.x, a.y + b.y};
    return result;
}

Vector2f operator-(Vector2f a, Vector2f b) 
{
    Vector2f result = {a.x - b.x, a.y - b.y};
    return result;
}

float operator*(Vector2f a, Vector2f b) 
{
    return a.x * b.x + a.y * b.y;
}

Vector2f operator*(Vector2f a, float b) 
{
    Vector2f result = {a.x * b, a.y * b};
    return result;
}

Vector2f operator*(float a, Vector2f b) 
{
    return b * a;
}

Vector2f operator/(Vector2f a, float b) 
{
    Vector2f result = {a.x / b, a.y / b};
    return result;
}

Vector2f operator+(Vector2f a) 
{
    return a;
}

Vector2f operator-(Vector2f a) 
{
    Vector2f result;
    result.x = -a.x;
    result.y = -a.y;
    return result;
}

bool operator==(Vector2f a, Vector2f b) 
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(Vector2f a, Vector2f b) 
{
    return !(a == b);
}

Vector2f& operator+=(Vector2f& a, Vector2f b) 
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2f& operator-=(Vector2f& a, Vector2f b) 
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vector2f& operator*=(Vector2f& a, float b) 
{
    a.x *= b;
    a.y *= b;
    return a;
}

Vector2f& operator/=(Vector2f& a, float b) 
{
    a.x /= b;
    a.y /= b;
    return a;
}

std::ostream& operator<<(std::ostream& out, Vector2f a) 
{
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector2f& a) 
{
    in >> a.x >> a.y;
    return in;
}