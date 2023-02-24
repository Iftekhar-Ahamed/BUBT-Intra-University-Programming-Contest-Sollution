
#include <bits/stdc++.h>
using namespace std;

#define FasterIO                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

double dist(double x1, double y1, double x2, double y2)
{
    double dst, a, b, c;
    a = (x1 - x2) * (x1 - x2);
    b = (y1 - y2) * (y1 - y2);
    c = a + b;
    c = sqrtl(c);

    return c;
}

void solution()
{
    int t, ax, ay, dx, dy, h, r;
    char c;
    double dst;
    cin >> t; // test case
    while (t--)
    {
        cin >> h >> r;               // h is the height of the wall from the ground. r is the radius.
        cin >> c;                    // if outside c= o , if inside c= i .
        cin >> ax >> ay >> dx >> dy; // ant coordinate and Water droplets coordinate

        if (c == 'o')
        {
            dst = dist(ax, ay, dx, dy);
        }
        else if (c == 'i')
        {
            dy = (h + h) - dy; // x axis will always same
            dst = dist(ax, ay, dx, dy);
        }
        cout << fixed << setprecision(6) << dst << endl;
    }
}

int main()
{
    FasterIO;

    solution();
    return 0;
}
