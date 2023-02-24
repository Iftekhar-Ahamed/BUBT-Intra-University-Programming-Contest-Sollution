#include <iostream>
using namespace std;
#define ll long long int
const ll MM = 2e5 + 10;

#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

ll gold[MM], dp[MM];

int main()
{
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> gold[i];
        }
        dp[0] = 0;
        dp[1] = gold[1];
        dp[2] = gold[1] + gold[2];
        for (int i = 3; i <= n; i++)
        {
            // if you ignore the current room
            ll ans1 = dp[i - 1];

            // If you take from this room then also the previous room
            // and ignore the (i-2)th room
            ll ans2 = dp[i - 3] + gold[i - 1] + gold[i];

            // If you take from this room and
            // ignore the (i-1)th room
            ll ans3 = dp[i - 2] + gold[i];

            dp[i] = max(ans1, max(ans2, ans3));
        }
        cout << dp[n] << endl;
    }
    return 0;
}
