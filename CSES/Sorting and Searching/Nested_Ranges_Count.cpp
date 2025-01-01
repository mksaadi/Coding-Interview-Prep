#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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


struct range
{
    int l, r, idx;
    bool operator<(const range& a) const
    {
        if ( l == a.l )
            return r > a.r;
        return l < a.l;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<range>ranges(n);
    for ( int i = 0; i < n; i++ )
    {
        int l, r;
        cin >> l >> r;
        ranges[i].idx = i;
        ranges[i].l = l;
        ranges[i].r = r;
    }
    sort(all(ranges));
    vector<int> contained(n, 0);
    vector<int> contains(n, 0);
    ordered_set<pi>rb;

    for ( int i = 0; i < n; i++ )
    {
        rb.insert({ ranges[i].r, -i });
        contained[ranges[i].idx] = sz(rb) - rb.order_of_key({ ranges[i].r, ( -1 * i ) }) - 1;
    }
    rb.clear();
    for ( int i = n - 1; i >= 0; i-- )
    {
        rb.insert({ ranges[i].r,-i });
        contains[ranges[i].idx] = rb.order_of_key({ ranges[i].r, ( -1 * i ) });
    }
    for ( int i = 0; i < n; i++ )
    {
        cout << contains[i] << " ";
    }
    cout << nl;
    for ( int i = 0; i < n; i++ )
    {
        cout << contained[i] << " ";
    }
    cout << nl;
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