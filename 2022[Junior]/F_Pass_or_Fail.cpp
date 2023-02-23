#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t, cn = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++cn << ": ";
        string a, b, c;
        int sum = 0, temp = 0;
        cin >> a >> b >> c;
        if (a == "A" || b == "A")
        {
            cout << "FaiL" << endl;
        }
        else
        {
            if (a.size() == 1)
            {
                sum += a[0] - '0';
            }
            if (a.size() == 2)
            {
                temp = 0;
                temp = ((a[0] - '0') * 10) + (a[1] - '0');
                sum += temp;
            }
            if (b.size() == 1)
            {
                sum += b[0] - '0';
            }
            if (b.size() == 2)
            {
                temp = 0;
                temp = ((b[0] - '0') * 10) + (b[1] - '0');
                sum += temp;
            }
            if (c.size() == 1)
            {
                sum += c[0] - '0';
            }
            if (c.size() == 2)
            {
                temp = 0;
                temp = ((c[0] - '0') * 10) + (c[1] - '0');
                sum += temp;
            }
            if (sum >= 40 && sum <= 100)
                cout << "PasS" << endl;
            else
                cout << "FaiL" << endl;
        }
    }
}
