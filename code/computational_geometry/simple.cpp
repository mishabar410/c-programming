#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

struct Point
{
    long double x, y;
    Point (long double a = 0, long double b = 0)
    {
        x = a;
        y = b;
    }
    long double dist()
    {
        return sqrt(x * x + y * y);
    }
    long double dist2() // работает без корня, поэтому быстрее
    {                   // нужно чтобы сравнить расстояния для двух дочек
        return x * x + y * y;
    }
};

istream & operator >> (istream & in, Point & P)
{
    in >> P.x >> P.y;
    return in;
}

ostream & operator << (ostream & out, const Point & P)
{
    // лучше всегда в такие функции передавать объект типа точка по константной ссылке, если не модифицируем
    out << P.x << " " << P.y;
    return out;
}


struct Vector
{
    long double x, y;

    Vector (long double a = 0, long double b = 0)
    {
        x = a;
        y = b;
    }
    Vector (const Point & A, const Point & B)
    {
        x = B.x - A.x;
        y = B.y - A.y;
    }
    long double angle() // считаем полярный угол
    {
        return atan2(y, x);
    }
    long double length()
    {
        return sqrt(x * x + y * y);
    }
};

long double degrees(long double radians)
{
    // переводит радианы в градусы
    return radians / M_PI * 180;
}

long double scalar_product(const Vector & a, const Vector & b)
{
    // скалярное произведение
    return a.x * b.x + a.y * b.y;
}

long double module_cross_product(const Vector & a, const Vector & b)
{
    // длина вектора, равного векторному произведению векторов a и b
    return a.x * b.y - b.x * a.y;
}

long double angle_between(Vector & a, Vector & b)
{

    return acos(scalar_product(a, b) / (a.length() * b.length()));
}

long double triangle_area(Point & a, Point & b, Point & c)
{
    // площадь треугольника по точкам a, b, c
    Vector ab(a, b);
    Vector ac(a, c);
    return abs(module_cross_product(ab, ac) / 2);
}

Vector operator +(const Vector & a, const Vector & b)
{
    // здесь вариант с константной ссылкой может не работать если внутри какие-то промежуточные значения
    return Vector(a.x + b.x, a.y + b.y);
}

Vector operator -(const Vector & a, const Vector & b)
{
    return Vector(a.x - b.x, a.y - b.y);
}

Vector operator *(const Vector & a, double k)
{
    return Vector(a.x * k, a.y * k);
}

Vector operator *(double k, const Vector & a)
{
    return Vector(a.x * k, a.y * k);
}

Vector operator /(const Vector & a, double k)
{
    return Vector(a.x / k, a.y / k);
}

Point operator +(const Point & a, const Vector & b)
{
    return Point(a.x + b.x, a.y + b.y);
}

Point operator -(const Point & a, const Vector & b)
{
    return Point(a.x - b.x, a.y - b.y);
}

istream & operator >> (istream & in, Vector & V)
{
    in >> V.x >> V.y;
    return in;
}

ostream & operator << (ostream & out, const Vector & V)
{
    out << V.x << " " << V.y;
    return out;
}

Point get_point(long double a, long double b, long double c)
{
    // дает точку, которая лежит на этой прямой
    Point A((-a * c) / (a * a + b * b), (-b * c) / (a * a + b * b));
    return A;
}

Vector get_vector(long double a, long double b, long double c)
{
    // дает вектор, который лежит на этой прямой
    Point A = get_point(a, b, c);
    Point B(A.x - b, A.y + a);
    Vector X(A, B);
    return X;
}

long double dist_to_ray(Point P, Point A, Point B)
{
    // расстояние от точки P до луча AB
    Vector AB(A, B);
    Vector AP(A, P);
    if (scalar_product(AB, AP) < 0) return AP.length();
    return abs(module_cross_product(AB, AP)) / AB.length();
}

long double dist_to_segment(Point P, Point A, Point B)
{
    // расстояние от точки P до отрезка AB
    Vector AB(A, B);
    Vector AP(A, P);
    Vector BA(B, A);
    Vector BP(B, P);
    long double scal1 = scalar_product(AB, AP);
    long double scal2 = scalar_product(BA, BP);
    if (scal1 > 0 && scal2 > 0) return abs(module_cross_product(AB, AP)) / AB.length();
    else return min(AP.length(), BP.length());
}

int one_half_plane(Vector R, Vector XA, Vector XB)
{
    // проверяет лежат ли точки а и б по одну сторону от вектора R
    if ((module_cross_product(R, XA) >= 0 && module_cross_product(R, XB) >= 0) ||
    (module_cross_product(R, XA) <= 0 && module_cross_product(R, XB) <= 0))
    {
        return 1;
    }
    else return 0;
}

int segments_intersects(Point A, Point B, Point C, Point D)
{
    // проверяет отрезки на пересечение
    Vector AB(A, B);
    Vector CD(C, D);
    Vector CA(C, A);
    Vector CB(C, B);
    Vector AD(A, D);
    Vector DB(D, B);
    if (!module_cross_product(AB, CD))
    {
        if (CA.length() + CB.length() == AB.length() || AD.length() + DB.length() == AB.length())
        {
            return 1;
        }
        if (CD.length() == CA.length() + AD.length() || CD.length() == CB.length() + DB.length())
        {
            return 1;
        }
        else return 0;
    }
    else
    {
        if ((module_cross_product(CD, CA) >= 0 && module_cross_product(CD, CB) <= 0) ||
        (module_cross_product(CD, CA) <= 0 && module_cross_product(CD, CB) >= 0))
        {
            if ((module_cross_product(AB, -1 * CA) >= 0 && module_cross_product(AB, AD) <= 0) ||
                (module_cross_product(AB, -1 * CA) <= 0 && module_cross_product(AB, AD) >= 0))
                {
                    return 1;
                }
            else return 0;
        }
        else return 0;
    }
}

Point common_point(long double a1, long double b1, long double c1, long double a2, long double b2, long double c2)
{
    // точка пересечения двух прямых
    // нет проверки на параллельность
    Point A;
    A.x = -1 * (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
    A.y = -1 * (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
    return A;
}

void find_line(Point A, Point B)
{
    // печатает коэффициенты a b и c прямой, которой принадлежат точки A и B
    cout << B.y - A.y << ' ' << A.x - B.x << ' ' << A.y * B.x - A.x * B.y;
}

Point find_bisector(Point A, Point B, Point C)
{
    // находим основание биссектрисы из угла BAC
    Point P;        // не работает
    Vector AB(A, B);
    Vector AC(A, C);
    Vector BC(B, C);
    long double k = AC.length() / AB.length();
    P.x = (k * C.x + B.x) / (k + 1);
    P.y = (k * C.y + B.y) / (k + 1);
    return P;
}

int main()
{
    Point A, B, C;
    cout.precision(20);
    cin >> A >> B >> C;
    cout << find_bisector(A, B, C);
    return 0;
}
