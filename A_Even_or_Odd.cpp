#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll answer[2100005];
ll ar[2100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        ll cnt = 0;
        for (ll j = 0; j <= 63; j++)
        {
            if (ar[i] & (1ll << j))
                cnt++;
        }
        if (cnt & 1)
            answer[i] = 1;
        answer[i] += answer[i - 1];
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll left, right;
        cin >> left >> right;
        cout << (right - left + 1) - (answer[right] - answer[left - 1]) << " "; /// even part
        cout << answer[right] - answer[left - 1] << "\n";                       ////odd part
    }
    return 0;
}
