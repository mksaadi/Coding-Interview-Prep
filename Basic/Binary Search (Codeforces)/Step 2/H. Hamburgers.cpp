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

ll nb, ns, nc;
ll r;
ll pb, ps, pc;
string str;
// check if 'mid' number of hamburgers are possible
bool possible(ll mid)
{
    ll b_needed = count(all(str), 'B') * mid;
    ll s_needed = count(all(str), 'S') * mid;
    ll c_needed = count(all(str), 'C') * mid;
    ll cur_b = nb;
    ll cur_s = ns;
    ll cur_c = nc;
    ll cur_r = r;

    if ( b_needed > nb )
    {
        ll extra_b_needed = b_needed - nb;
        ll extra_cost = ( extra_b_needed * pb );

        if ( extra_cost <= cur_r )
        {
            cur_b += extra_b_needed;
            cur_r -= extra_cost;
        }

    }
    if ( s_needed > ns )
    {
        ll extra_s_needed = s_needed - ns;
        ll extra_cost = ( extra_s_needed * ps );
        if ( extra_cost <= cur_r )
        {
            cur_s += extra_s_needed;
            cur_r -= extra_cost;
        }

    }
    if ( c_needed > nc )
    {
        ll extra_c_needed = c_needed - nc;
        ll extra_cost = ( extra_c_needed * pc );
        if ( extra_cost <= cur_r )
        {
            cur_c += extra_c_needed;
            cur_r -= extra_cost;
        }

    }
    if ( ( cur_s >= s_needed ) && ( cur_b >= b_needed ) && ( cur_c >= c_needed ) )
    {
        return true;
    }
    return false;

}


int main()
{
    FastIO;
    cin >> str;

    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;



    ll low = 0; // always possible
    ll high = ( 2 * nb ) + ( r / pb );
    while ( high - low > 1 )
    {
        ll mid = low + ( high - low ) / 2;
        if ( possible(mid) )
        {
            low = mid;
        }
        else high = mid;
    }
    cout << low << nl;


    return 0;
}