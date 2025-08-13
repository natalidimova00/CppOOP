#include <iostream>
#include <cmath>
#include <stdexcept>

const double EPS = 1e-9;

struct Point
{
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

class Line
{
private:
    double A, B, C; // Ax + By + C = 0

public:
    Line(const Point& p1, const Point& p2) 
    {
        A = p1.y - p2.y;
        B = p2.x - p1.x;
        C = p1.x * p2.y - p2.x * p1.y;
    }    
    
    bool operator==(const Line& other) const 
    {
        return fabs(A * other.B - other.A * B) < EPS;
    }

    bool contains(const Point& p) const 
    {
        return fabs(A * p.x + B * p.y + C) < EPS;
    }

    Point intersection(const Line& other) const 
    {
        double det = A * other.B - other.A * B;
        if (fabs(det) < EPS){
            throw ("The lines are parallel");
        }
        double x = (B * other.C - other.B * C) / det;
        double y = (other.A * C - A * other.C) / det;
        return Point(x, y);
    }

    Line angleBisector(const Line& other) const
    {
        double norm1 = sqrt(A * A + B * B);
        double norm2 = sqrt(other.A * other.A + other.B * other.B);

        double A1 = A / norm1;
        double B1 = B / norm1;
        double C1 = C / norm1;

        double A2 = other.A / norm2;
        double B2 = other.B / norm2;
        double C2 = other.C / norm2;

        double Ab = A1 - A2;
        double Bb = B1 - B2;
        double Cb = C1 - C2;

        return LineFromABC(Ab, Bb, Cb);
    }

    static Line LineFromABC(double a, double b, double c)
    {
        Line l(Point(0,0), Point(1,1));
        l.A = a;
        l.B = b;
        l.C = c;
        return l;
    }

    friend std::ostream& operator<< (std::ostream& os, const Line& l)
    {
        os << l.A << "x + " << l.B << "y + " << l.C << " = 0";
        return os;
    }
};

int main(){
    Point p1(0,0), p2(1, 1), p3(0, 1), p4(1, 2);
    Line l1(p1, p2), l2(p3, p4);

    std::cout <<  "Are the lines " << l1 <<  " and " << l2 << " parallel? " << (l1 == l2 ? "Yes" : "No") << std::endl;

    Point t(2, 2);
    std::cout << "Is the point ("<< t.x << "," << t.y << ") on the line " << l1 << "? " << (l1.contains(t) ? "Yes" : "No") << std::endl;
}