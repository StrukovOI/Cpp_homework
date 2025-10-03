#include <stdio.h>
#include <cmath>

struct point 
{
    double x;
    double y;
};
typedef struct point Point;

struct triangle 
{
    Point a;
    Point b;
    Point c;
};
typedef struct triangle Triangle;

void print_point (const Point* o)
{
    printf("(%.2f, %.2f)\n", o->x, o->y);
}

void print_triangle(Triangle* tr)
{
    printf("{(%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)}\n", tr->a.x, tr->a.y, tr->b.x, tr->b.y, tr->c.x, tr->c.y);
}

float distance (const Point* a, const Point* b)
{
    return pow(pow(a->x - b->x, 2) + pow(a->y - b->y, 2), 0.5);
}

float get_triangle_perimeter (const Triangle* tr)
{
    return pow(pow(tr->a.x - tr->b.x, 2) + pow(tr->a.y - tr->b.y, 2), 0.5) + pow(pow(tr->a.x - tr->c.x, 2) + pow(tr->a.y - tr->c.y, 2), 0.5) + pow(pow(tr->c.x - tr->b.x, 2) + pow(tr->c.y - tr->b.y, 2), 0.5);
}

Triangle moved_triangle(const Triangle* tr, Point v)
{
    Triangle result;
    result.a.x = tr->a.x + v.x;
    result.a.y = tr->a.y + v.y;
    result.b.x = tr->b.x + v.x;
    result.b.y = tr->b.y + v.y;
    result.c.x = tr->c.x + v.x;
    result.c.y = tr->c.y + v.y;
    return result;
}

void move_triangle(Triangle* tr, Point v)
{
    tr->a.x += v.x;
    tr->a.y += v.y;
    tr->b.x += v.x;
    tr->b.y += v.y;
    tr->c.x += v.x;
    tr->c.y += v.y;
}

int main()
{
    Triangle t = {{1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50}};
    printf("Perimeter = %.2f\n", get_triangle_perimeter(&t));
    
    Point d = {1.0, 1.0};

    print_triangle(&t);
    move_triangle(&t, d);
    print_triangle(&t);
    print_point(&d);
    printf("%f\n", distance(&t.a, &t.b));
    
    Triangle mv = moved_triangle(&t, d);
    print_triangle(&mv);
}
