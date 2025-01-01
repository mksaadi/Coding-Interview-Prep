#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

const int mx = 1e5;
vector<int> adj[mx];
vector<bool> visited(mx);

void dfs(int s)
{
    if (visited[s])
        return;
    visited[s] = true;
    cout << s << " ";
    for (auto child : adj[s])
    {
        dfs(child);
    }
}

int main()
{
    FastIO;
    // graph with n nodes and m edges
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    return 0;
}