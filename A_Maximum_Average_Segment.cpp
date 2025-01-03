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


// Given an array of n and a number d. Your task is to find the maximum average of a subarray of length d.

bool ok(double x, int d, vector<int>& a, int& start, int& end) {
    double sum = 0, pre = 0, min_pre = 0;
    for ( int i = 0; i < a.size(); i++ ) {
        sum += a[i] - x;
        if ( i >= d - 1 ) {
            if ( sum - min_pre >= 0 ) {
                end = i;
                return true;
            }
            pre += a[i - d + 1] - x;
            min_pre = min(min_pre, pre);
        }
    }
    start = end - d;
    return false;
}

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    double l = 0, r = 1e9;
    int start = 0, end = 0;
    for ( int i = 0; i < 100; i++ ) 
    {
        double m = ( l + r ) / 2;
        if ( ok(m, d, a, start, end) ) {
            l = m;
        }
        else {
            r = m;
        }
    }
    cout << start + 1 << " " << end + 1 << nl;

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