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
vector<int> dist(mx);
vector<int> parent(mx);
queue<int> q;

void bfs(int start)
{
    dist[start] = 0;
    parent[start] = start;
    visited[start] = true;
    q.push(start);
    while ( !q.empty() )
    {
        int cur_node = q.front();
        cout << cur_node << " ";
        q.pop();
        for ( auto child : adj[cur_node] )
        {
            if ( visited[child] )
                continue;
            visited[child] = true;
            dist[child] = dist[cur_node] + 1;
            parent[child] = cur_node;
            q.push(child);
        }
    }
    cout << nl;
}

int main()
{
    FastIO;
    // graph with n nodes and m edges
    int n, m;
    cin >> n >> m;
    for ( int i = 0; i < m; i++ )
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    // printing the distance of all the nodes from node 1

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Distance from 1 to " << i << " = " << dist[i] << nl;
    // }

    // print the distance of a particular node from 1 and it's path
    int destination;
    cin >> destination;
    cout << "Distance from node 1 to " << destination << " = " << dist[destination] << nl;
    // print the path from 1 to destination

    int temp = destination;
    while ( temp != 1 )
    {
        cout << temp << " --> ";
        temp = parent[temp];
    }
    cout << 1 << nl;
    return 0;
}