#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    double x, y;
};

class Polygon
{
    public:
    Point* points;
    Polygon(int number_of_points)
    {
        points=new Point[number_of_points];
    }

};

int Area(Polygon p, int n)
{
    double fArea = 0;
    for (int i = 0; i < n; ++i)
    {
        int x1 = p.points[i].x - p.points[0].x;
        int y1 = p.points[i].y - p.points[0].y;
        int x2 = p.points[i + 1].x - p.points[0].x;
        int y2 = p.points[i + 1].y - p.points[0].y;

        double cross_p = x1 * y2 - y1 * x2;
        fArea = fArea + cross_p;
    }

    int ans = abs(fArea / 2);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    Polygon p(n);

    for (int i = 0; i < n; ++i)
        cin >> p.points[i].x;

    for (int i = 0; i < n; ++i)
        cin >> p.points[i].y;

    cout << Area(p, n);
    return 0;
}