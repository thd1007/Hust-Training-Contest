#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int low[N], num[N], n, m, res;
vector <int> a[N];
int Time = 0;
stack <int> st;
void dfs(int u)
{
    low[u] = num[u] = ++Time;
    st.push(u);
    for (int v : a[u])
    {
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u])
    {
        res++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            low[v] = num[v] = 2e9;
        } while (v != u);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("input.txt", "r"))
        assert(freopen("input.txt", "r", stdin));
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!num[i]) dfs(i);
    }
    cout << res;
}
