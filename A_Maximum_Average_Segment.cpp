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
#define double long double
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


vi a(100005);
int n, d, l, r;


bool ok(double x)
{
    vector<double>pref_sum(n);
    pref_sum[0] = a[0] - x;
    vector<pair<double, double>>min_pref(n);
    min_pref[0].first = a[0] - x;
    min_pref[0].second = 0;
    for ( int i = 1; i < n; i++ )
    {
        pref_sum[i] = pref_sum[i - 1] + a[i] - x;
        if ( pref_sum[i] < min_pref[i - 1].first )
        {
            min_pref[i].first = pref_sum[i];
            min_pref[i].second = i;
        }
        else
        {
            min_pref[i].first = min_pref[i - 1].first;
            min_pref[i].second = min_pref[i - 1].second;
        }
    }
    for ( int i = d - 1; i < n; i++ )
    {
        if ( pref_sum[i] >= 0 )
        {
            l = 0;
            r = i;
            return true;
        }
        if ( i - d >= 0 && pref_sum[i] - min_pref[i - d].first >= 0 )
        {
            l = min_pref[i - d].second + 1;
            r = i;
            return true;
        }
    }
    return false;

}

void solve()
{
    cin >> n >> d;
    a.resize(n);
    for ( int i = 0; i < n; i++ )
    {
        cin >> a[i];
    }
    double low = 0.0;
    double high = 105.00;

    for ( int i = 0; i < 200; i++ )
    {
        double mid = ( high + low ) / 2.0;
        if ( ok(mid) )
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << l + 1 << " " << r + 1 << nl;

}
int main()
{
    FastIO;
    cout.setf(std::ios::fixed, std::ios::floatfield);
    cout.precision(9);
    int t = 1;
    // cin >> t;
    while ( t-- )
    {
        solve();
    }
    return 0;
}