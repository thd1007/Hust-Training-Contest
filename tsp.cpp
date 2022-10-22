#include<bits/stdc++.h>
using namespace std;
const int N = 17;
int n, m, a[N][N], best = 2e9;
int dp[80000][N];
bool vis[N];
void Try(int cur, int cursum, int cnt, int curmask)
{
    if (cnt == n + 1)
    {
        best = min(best, cursum + a[cur][0]);
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i]) continue;
        int nextmask = curmask | (1 << cur);
        if (cursum + a[cur][i] > dp[nextmask][i]) continue;
        dp[nextmask][i] = cursum + a[cur][i];
        vis[i] = true;
        Try(i, cursum + a[cur][i], cnt + 1, nextmask);
        vis[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("input.txt", "r"))
        assert(freopen("input.txt", "r", stdin));
    cin >> n;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    vis[0] = true;
    Try(0, 0, 1, 1);
    cout << best;
}
