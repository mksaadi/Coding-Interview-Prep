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

ll modpow(ll x, ll n) { if ( n == 0LL ) return 1LL % MOD; ll u = modpow(x, n / 2LL); u = ( u * u ) % MOD; if ( n % 2LL == 1LL ) u = ( u * x ) % MOD; return u; }

ll geosum(ll base, ll pow)
{
    ll numerator = ( ( modpow(base, pow + 1) - 1 ) + MOD ) % MOD;
    ll denominator = modpow(base - 1, MOD - 2);
    return ( numerator * denominator ) % MOD;
}

ll multiply(ll a, ll b, ll mod)
{
    return ( ( a % mod ) * ( b % mod ) ) % mod;
}
void solve()
{
    ll n;
    ll num_divs = 1;
    ll sum_divs = 1;
    ll prod_divs = 1;
    ll cnt = 1;
    cin >> n;

    for ( ll i = 0; i < n; i++ )
    {
        ll x, k;
        cin >> x >> k;
        num_divs *= ( k + 1 ) % MOD;
        num_divs %= MOD;
        sum_divs *= geosum(x, k);
        sum_divs %= MOD;
        prod_divs = multiply(modpow(prod_divs, k + 1), modpow(modpow(x, k * ( k + 1 ) / 2), cnt), MOD);
        cnt = multiply(cnt, k + 1, MOD - 1);
    }
    cout << num_divs << " " << sum_divs << " " << prod_divs << nl;
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