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




void solve()
{
    int n, m;
    cin >> n >> m;
    vi pos(n);
    vi a(n);
    for ( int i = 0; i < n; i++ )
    {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    int inv = 1;
    for ( int i = 1; i < n; i++ )
    {
        inv += ( pos[i] < pos[i - 1] );
    }
    for ( int i = 0; i < m; i++ )
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        set<pair<int, int>>st;
        if ( a[x] + 1 < n )st.insert({ a[x] ,a[x] + 1 });
        if ( a[x] - 1 >= 0 )st.insert({ a[x] - 1,a[x] });
        if ( a[y] + 1 < n )st.insert({ a[y],a[y] + 1 });
        if ( a[y] - 1 >= 0 )st.insert({ a[y] - 1,a[y] });
        for ( auto s : st )
        {
            inv -= ( pos[s.first] > pos[s.second] );
        }
        swap(a[x], a[y]);
        pos[a[x]] = x;
        pos[a[y]] = y;
        for ( auto s : st )
        {
            inv += ( pos[s.first] > pos[s.second] );
        }
        cout << inv << nl;
        st.clear();
    }
}
int main()
{
    FastIO;
    int t = 1;
    // cin >> t;
    while ( t-- )
    {
        solve();
    }
    return 0;
}