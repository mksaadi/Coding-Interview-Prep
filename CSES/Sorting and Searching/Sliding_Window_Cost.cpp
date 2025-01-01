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
    int n, k;
    cin >> n >> k;
    vi a(n);
    set<pi>left, right;
    int left_set_size = ( k + 1 ) / 2;
    int right_set_size = k - left_set_size;
    for ( int i = 0; i < n; i++ )
    {
        cin >> a[i];
    }
    if ( k == 1 )
    {
        for ( int i = 0; i < n; i++ )
        {
            cout << 0 << " ";
        }
        cout << nl;
        return;
    }
    if ( k == 2 )
    {
        for ( int i = 0; i + 1 < n; i++ )
        {
            cout << abs(a[i] - a[i + 1]) << " ";
        }
        cout << nl;
        return;
    }
    vpi val;
    ll left_sum = 0;
    ll right_sum = 0;
    for ( int i = 0; i < k; i++ )
    {
        val.push_back({ a[i],i });
    }
    sort(all(val));
    for ( int i = 0; i < left_set_size; i++ )
    {
        left.insert(val[i]);
        left_sum += val[i].ff;
    }
    for ( int i = left_set_size; i < k; i++ )
    {
        right.insert(val[i]);
        right_sum += val[i].ff;
    }
    // dbg(left);
    // dbg(right);
    ll median = left.rbegin()->ff;
    ll cost = ( ( median * sz(left) ) - left_sum ) + ( right_sum - ( median * sz(right) ) );
    cout << cost << " ";
    for ( int i = 1; i < n - k + 1; i++ )
    {
        if ( left.find({ a[i - 1],i - 1 }) != left.end() )
        {
            left_sum -= a[i - 1];
            left.erase(left.find({ a[i - 1],i - 1 }));
        }
        else
        {
            right_sum -= a[i - 1];
            right.erase(right.find({ a[i - 1],i - 1 }));
        }
        if ( !left.empty() && a[i + k - 1] >= left.rbegin()->ff )
        {
            right.insert({ a[i + k - 1],i + k - 1 });
            right_sum += a[i + k - 1];
        }
        else
        {
            left.insert({ a[i + k - 1],i + k - 1 });
            left_sum += a[i + k - 1];
        }
        if ( sz(left) > left_set_size )
        {
            right.insert(*left.rbegin());
            right_sum += left.rbegin()->ff;
            left_sum -= left.rbegin()->ff;
            left.erase(*left.rbegin());
        }
        if ( sz(right) > right_set_size )
        {
            left.insert(*right.begin());
            left_sum += right.begin()->ff;
            right_sum -= right.begin()->ff;
            right.erase(*right.begin());
        }
        median = left.rbegin()->ff;
        cost = ( ( median * sz(left) ) - left_sum ) + ( right_sum - ( median * sz(right) ) );
        cout << cost << " ";
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