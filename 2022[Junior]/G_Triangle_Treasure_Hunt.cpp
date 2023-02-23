#include <stdio.h>
#include <math.h>

#define ll long long int

struct Point
{
    ll x, y;
};

double area(Point p1, Point p2, Point p3)
{
    return abs(0.5 * (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)));
}

int pointStatus(Point p1, Point p2, Point p3, Point p)
{
    double totalArea = area(p1, p2, p3);
    double area1 = area(p, p2, p3);
    double area2 = area(p1, p, p3);
    double area3 = area(p1, p2, p);
    if (totalArea == area1 + area2 + area3)
    {
        if (area1 == 0 || area2 == 0 || area3 == 0)
            return 1;
        return 2;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        Point p1, p2, p3, p;
        scanf("%lld %lld", &p1.x, &p1.y);
        scanf("%lld %lld", &p2.x, &p2.y);
        scanf("%lld %lld", &p3.x, &p3.y);
        scanf("%lld %lld", &p.x, &p.y);
        int stat = pointStatus(p1, p2, p3, p);
        if (stat == 1)
        {
            printf("Try Again…\n");
        }
        else if (stat == 2)
        {
            printf("Door Unlocked\n");
        }
        else
        {
            printf("GET OUT !!\n");
        }
    }
    return 0;
}
