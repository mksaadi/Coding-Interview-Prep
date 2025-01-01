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


// given a maximum segment sum = mid, check if k segments can be made so that segment sum doesn't exceed mid
ll max_el = 0;

bool possible(vl& a, ll mid, int k)
{
    if ( mid < max_el )
    {
        return false;
    }
    int segs = 1;
    ll seg_sum = 0LL;
    for ( int i = 0; i < sz(a); i++ )
    {
        if ( seg_sum + a[i] <= mid )
        {
            seg_sum += a[i];
        }
        else
        {
            segs++;
            seg_sum = a[i];
        }
    }
    return ( segs <= k );
}

int main()
{
    FastIO;
    int n, k;
    cin >> n >> k;
    vl a(n);
    for ( int i = 0; i < n; i++ )
    {
        cin >> a[i];
        max_el = max(max_el, a[i]);
    }
    ll high = accumulate(all(a), 0LL); // always possible
    ll low = 0LL; // impossible

    while ( high - low > 1 )
    {
        ll mid = ( low + ( high - low ) / 2LL );
        if ( possible(a, mid, k) )
        {
            high = mid;
        }
        else low = mid;
    }
    cout << high << nl;

    return 0;
}