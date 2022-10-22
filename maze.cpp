#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int m, n, stx, sty, a[N][N];
struct ii { int x, y; };
queue <ii> q;
int vis[N][N];
int r[] = {-1, 0, 1, 0};
int c[] = {0, -1, 0, 1};
inline bool in(int x, int y)
{
    return (0 <= x && x < m && 0 <= y && y < n);
}
int bfs()
{
    stx--; sty--;
    q.push({stx, sty});
    vis[stx][sty] = 1;
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int u = x + r[dir], v = y + c[dir];
            if (!in(u, v)) return vis[x][y];
            if (vis[u][v] || a[u][v]) continue;
            vis[u][v] = vis[x][y] + 1;
            q.push({u, v});
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> stx >> sty;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    cout << bfs();
}
