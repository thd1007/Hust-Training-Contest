#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int low[N], num[N], n, m;
vector <int> a[N];
int Time = 0;
int cntnode  = 0, edge = 0;
bool node[N];
void dfs(int u, int pre)
{
	int nc = 0;
	low[u] = num[u] = ++Time;
	for (int v : a[u])
	{
		if (v == pre) continue;
		if (num[v] != 0)
			low[u] = min(low[u], num[v]);
		else
		{
			dfs(v, u);
			nc++;
			low[u] = min(low[u], low[v]);
			if (low[v] >= num[v])
				edge++;
			if (u == pre)
			{
				if (nc >= 2) node[u] = true;
			}
			else
			{
				if (low[v] >= num[u]) node[u] = true;
			}
		}
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
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i)
		if (!num[i]) dfs(i, i);
	for (int i = 1; i <= n; ++i) if (node[i])  cntnode++;
	cout << cntnode << ' ' << edge;
} 
