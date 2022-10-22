#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int n, k = 1, a[N][N], best = 2e9;
int p[15], dp[24][531444];
bool vis[N];
void Try(int cur, int cursum, int guest, int cnt, int curm)
{
    if (cnt == 2 * n)
    {
        best = min(best, cursum + a[cur][0]);
        return;
    }
    if (cursum > best) return;
    for (int i = 1; i <= 2 * n; ++i)
    {
        if (vis[i]) continue;
        if (i <= n)
        {
            if (guest == k) continue;
            int nextm = curm + p[i - 1];
            if (dp[cur][nextm] == 0) dp[cur][nextm] = 2e9;
            if (cursum + a[cur][i] > dp[cur][nextm]) continue;
            dp[cur][nextm] = cursum + a[cur][i];
            vis[i] = true;
            Try(i, cursum + a[cur][i], guest + 1, cnt + 1, nextm);
            vis[i] = false;
        }
        if (i > n)
        {
            if (guest == 0) continue;
            if (!vis[i - n]) continue;
            int nextm = curm + p[i - 1 - n];
            if (dp[cur][nextm] == 0) dp[cur][nextm] = 2e9;
            if (cursum + a[cur][i] > dp[cur][nextm]) continue;
            dp[cur][nextm] = cursum + a[cur][i];
            vis[i] = true;
            Try(i, cursum + a[cur][i], guest - 1, cnt + 1, nextm);
            vis[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("input.txt", "r"))
        assert(freopen("input.txt", "r", stdin));
    p[0] = 1;
    for (int i = 1; i <= 12; ++i)
    {
        p[i] = p[i - 1] * 3;
    }
    cin >> n;
    for (int i = 0; i <= 2 * n; ++i)
        for (int j = 0; j <= 2 * n; ++j)
        {
            cin >> a[i][j];
        }
    vis[0] = true;
    Try(0, 0, 0, 0, 0);
    cout << best;
}
