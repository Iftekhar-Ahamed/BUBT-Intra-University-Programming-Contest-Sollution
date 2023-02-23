#include <bits/stdc++.h>
using namespace std;

#define FasterIO                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

bool cord[100011][100];
int r = 0, c = 0;

void bin(long long int n, int sz)
{
    vector<bool> bit;
    if (n == 0)
        bit.push_back(0);
    while (n != 0)
    {
        bit.push_back(n & 1);
        n >>= 1;
    }
    int siz = bit.size();

    if (siz < sz)
    {
        int baki = sz - siz;
        for (int i = 0; i < baki; i++)
            bit.push_back(0);
    }

    reverse(bit.begin(), bit.end());
    c = 0;
    for (bool i : bit)
    {
        // cout<<i<<' ';
        cord[r][c] = i;
        c++;
    }
    r++;
    // cout<<'\n';
}

int sizee(long long int n)
{
    int cnt = 0;
    if (n == 0)
        cnt = 1;
    while (n != 0)
    {
        cnt++;
        n >>= 1;
    }
    return cnt;
}

bool visited[100011][100];
void zero()
{
    for (int i = 0; i < 100011; i++)
    {
        for (int j = 0; j < 100; j++)
            visited[i][j] = 0;
    }
}
bool deyal = 0, paici = 0;

void dfs(int si, int sj, int di, int dj)
{
    if (si == di && sj == dj)
    {
        paici = 1;
        return; // found the destination
    }

    if (si < 0 || si > di)
        return; // out of bound
    if (sj < 0 || sj > dj)
        return; // out of bound

    if (visited[si][sj] == 1)
        return; // this index already visited
    else
    {
        visited[si][sj] = 1;
        if (visited[si + 1][sj] == 0 && cord[si + 1][sj] == deyal)
        {
            dfs(si + 1, sj, di, dj);
        }

        if (visited[si - 1][sj] == 0 && cord[si - 1][sj] == deyal)
        {
            dfs(si - 1, sj, di, dj);
        }

        if (visited[si][sj + 1] == 0 && cord[si][sj + 1] == deyal)
        {
            dfs(si, sj + 1, di, dj);
        }

        if (visited[si][sj - 1] == 0 && cord[si][sj - 1] == deyal)
        {
            dfs(si, sj - 1, di, dj);
        }
    }
}

void solution()
{
    zero();
    int n;
    cin >> n;
    long long int ar[n + 4], mx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        mx = max(mx, ar[i]);
    }

    // for(int i=0;i<n;i++)cout<<ar[i]<<' ';
    // cout<<endl;

    int sz = sizee(mx);
    for (int i = 0; i < n; i++)
    {
        bin(ar[i], sz);
    }
    // cout<<"\n\n";
    deyal = cord[0][0];
    //    for(int i=0; i<n; i++)
    //    {
    //        for(int j=0; j<sz; j++)
    //            cout<<cord[i][j]<<' ';
    //        cout<<'\n';
    //    }

    dfs(0, 0, n - 1, sz - 1);

    if (paici == 0)
        cout << "Let\'s make ice-cream.\n";
    else
        cout << "Yeeee! ice-cream.\n";
}

int main()
{
    FasterIO;
    solution();
    return 0;
}
