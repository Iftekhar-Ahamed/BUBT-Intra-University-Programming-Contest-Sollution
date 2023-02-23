#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int testCase, t = 0;
    cin >> testCase;
    while (testCase--)
    {
        int attempt1, attempt2, attempt3;
        cin >> attempt1 >> attempt2 >> attempt3;
        cout << "Case " << ++t << ": " << 150 - (150 * (attempt1 + attempt2 + attempt3)) / 100 << endl;
    }
    return 0;
}
