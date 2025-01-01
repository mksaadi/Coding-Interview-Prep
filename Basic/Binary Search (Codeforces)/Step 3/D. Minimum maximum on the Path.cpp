#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned  long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using ld = long double;
using vld = vector<ld>;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define ff first
#define ss second
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MOD 1000000007
#define INF 1e18
#define PI 3.141592653589793238462
#define set_precision(x) cout.setf(std::ios::fixed, std::ios::floatfield);cout.precision(x);


#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x <<" = "; _print(x); cerr << nl;
#else
#define dbg(x)
#endif


void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}" << nl; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for ( T i : v ) { _print(i); cerr << " "; } cerr << "]" << nl; }
template <class T> void _print(set <T> v) { cerr << "[ "; for ( T i : v ) { _print(i); cerr << " "; } cerr << "]" << nl; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for ( T i : v ) { _print(i); cerr << " "; } cerr << "]" << nl; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for ( auto i : v ) { _print(i); cerr << " "; } cerr << "]" << nl; }


const int mx = 1e5;
vector<pair<int, int>> adj[mx + 2];
vector<bool> visited(mx + 2);
vector<int> dist(mx + 2, INT_MAX);
vector<int> parent(mx + 2, -1);

bool  bfs(int start, int max_weight, int d, int n)
{
    queue<pair<int, int>> q;
    fill(dist.begin(), dist.end(), INT_MAX);
    fill(parent.begin(), parent.end(), -1);
    dist[start] = 0;
    parent[start] = start;
    q.push({ start,0 });
    while ( !q.empty() )
    {
        int cur_node = q.front().first;
        int edge_count = q.front().second;
        // cout << cur_node << " ";

        if ( cur_node == n && edge_count <= d )
        {
            return true;
        }
        q.pop();

        for ( auto child : adj[cur_node] )
        {
            int next_node = child.first;
            int edge_weight = child.second;
            int next_edge_count = edge_count + 1;

            if ( edge_weight <= max_weight && next_edge_count <= d && dist[cur_node] + 1 < dist[next_node] )
            {
                dist[next_node] = dist[cur_node] + 1;
                parent[next_node] = cur_node;
                q.push({ next_node,next_edge_count });
            }

        }
    }
    return false;
}

int main()
{
    FastIO;
    // graph with n nodes and m edges
    int n, m, d;
    cin >> n >> m >> d;
    int max_weight = 0;
    for ( int i = 0; i < m; i++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        max_weight = max(max_weight, c);
    }

    int left = 0;
    int right = max_weight;
    int ans = -1;
    while ( left <= right )
    {
        int mid = ( left + right ) / 2;
        if ( bfs(1, mid, d, n) )
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }


    if ( ans != -1 )
    {
        bfs(1, ans, d, n);
        vector<int> path;
        int temp = n;
        while ( temp != 1 ) {
            path.push_back(temp);
            temp = parent[temp];
        }
        path.push_back(1);
        cout << sz(path) - 1 << nl;
        for ( int i = sz(path) - 1; i >= 0; i-- ) {
            cout << path[i] << " ";
        }
        cout << nl;
    }
    else cout << -1 << nl;

    return 0;
}