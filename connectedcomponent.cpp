#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> vertices[100005];
vector<int> visited(100005, false);
void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        vertices[u].push_back(v);
        vertices[v].push_back(u);
    }
}
void DFS(int u) {
    visited[u] = true;
    for (int i = 0; i < vertices[u].size(); i++) {
        int v = vertices[u][i];
        if (!visited[v]) {
            DFS(vertices[u][i]);
        }
    }
}
void solve() {
    int count = 0;
    for (int u = 1; u <= N; u++) {
        if (!visited[u]) {
            DFS(u);
            count++;
        }
    }
    cout << count << endl;
}
int main()
{
    input();
    solve();
    return 0;
}
