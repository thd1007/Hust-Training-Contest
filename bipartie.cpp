#include <bits/stdc++.h>
using namespace std;
int n, m;
int gr[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(gr, -1, sizeof(gr));
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        if (gr[u] == -1 && gr[v] == -1)
        {
            gr[u] = 1; gr[v] = 2;
            continue;
        }
        if (gr[u] != - 1)
        {
            if (gr[v] == -1) gr[v] = 3 - gr[u];
            else if (gr[v] == gr[u])
            {
                cout << 0;
                return 0;
            }
            continue;
        }
        if (gr[v] != - 1)
        {
            if (gr[u] == -1) gr[u] = 3 - gr[v];
            else if (gr[v] == gr[u])
            {
                cout << 0;
                return 0;
            }
            continue;
        }
    }
    cout << 1;
}
