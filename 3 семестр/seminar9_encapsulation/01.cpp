#include <iostream>
#include "point.hpp"
using std::cout, std::endl;

class Circle
{
private:
	Point center;
	float radius;

public:
    Circle(const Point& ctr, float rds)
    {
        center = ctr;
        if (rds >= 0)
        {
            radius = rds;
        }
        else
        {
            radius = 0;
        }
    }

    Circle()
    {
        center = {0, 0};
        radius = 1.0;
    }

    Circle(const Circle& circle)
    {
        center = circle.center;
        radius = circle.radius;
    }

    Point getCenter() const {return center;}
    float getRadius() const {return radius;}

    void setCenter(const Point& ctr) { center = ctr; }
    void setRadius(float rds)
    {
        if (rds >= 0)
        {
            radius = rds;
        }
        else
        {
            radius = 0;
        }
    }

    float area() const
    {
        return 3.14159 * radius * radius;
    }

    float distance(const Point& p) const
    {
        return std::abs(radius - center.distance(p));
    }

    bool isColliding(const Circle& c) const
    {
        if (radius + c.getRadius() >= center.distance(c.getCenter()))
        {
            return true;
        }
        return false;
    }

    void move(const Point& p)
    {
        center = center + p;
    }
};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "p + q = " << p + q << endl;


	Circle a({4, 1}, 3);
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.area() << endl;
	cout << "Distance from point p to circle a = " << a.distance(p) << endl;


	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;


	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;

}