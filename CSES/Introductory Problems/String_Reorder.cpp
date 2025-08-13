#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned  long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using ld = long double;
using vld = vector<ld>;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl " \n" 
#define ff first
#define ss second
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MOD 1000000007
#define INF 1e18
#define PI 3.141592653589793238462
#define set_precision(x) {cout<<fixed<<setprecision(x);}


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
    string str;
    cin >> str;
    int n = sz(str);
    map<char, int>freq;
    char max_char = 'a';
    for ( int i = 0; i < n; i++ )
    {
        freq[str[i]]++;
        if ( freq[str[i]] > freq[max_char] )
        {
            max_char = str[i];
        }
    }
    int limit = ( n & 1 ) ? ( n + 1 ) / 2 : n / 2;
    if ( freq[max_char] > limit )
    {
        cout << -1 << nl;
        return;
    }
    string res = "";
    while ( sz(res) < n )
    {
        bool placed = false;
        for ( auto& i : freq )
        {
            // try to append i.first to the string.
            if ( i.second > 0 && ( res.empty() || res.back() != i.first ) )
            {
                // append i
                res += i.first;
                i.second--;
                // now check if we can construct the rest of the string
                int suff_len = n - sz(res);
                bool ok = true;
                for ( auto& j : freq )
                {
                    if ( i.first != j.first )
                    {
                        if ( j.second > ( suff_len + 1 ) / 2 )
                        {
                            ok = false;
                            break;
                        }
                    }
                    else
                    {
                        if ( j.second > ( suff_len / 2 ) )
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                if ( !ok )
                {
                    res.pop_back();
                    i.second++;
                }
                else
                {
                    placed = true;
                    break;
                }
            }
        }
        if ( !placed )
        {
            cout << -1 << nl;
            return;
        }
    }

    cout << res << nl;
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