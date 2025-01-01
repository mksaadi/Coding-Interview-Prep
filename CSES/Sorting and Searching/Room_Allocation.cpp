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


struct Customer {
    int arrival, departure, idx;
    bool operator<(const Customer& a) const
    {
        if ( arrival == a.arrival )
            return departure < a.departure;
        return arrival < a.arrival;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<Customer> customers(n);
    priority_queue<pi, vector<pi>, greater<pi>> rooms;
    vector<int>res(n, 0);
    for ( int i = 0; i < n; i++ )
    {
        int a, d;
        cin >> a >> d;
        customers[i].arrival = a;
        customers[i].departure = d;
        customers[i].idx = i;
    }
    sort(all(customers));
    int room_num = 1;
    for ( int i = 0; i < n; i++ )
    {
        if ( rooms.empty() )
        {
            rooms.push({ customers[i].departure, room_num });
            res[customers[i].idx] = room_num++;
        }
        else
        {
            auto top = rooms.top();
            if ( top.first < customers[i].arrival )
            {
                rooms.pop();
                rooms.push({ customers[i].departure, top.second });
                res[customers[i].idx] = top.second;
            }
            else
            {
                rooms.push({ customers[i].departure, room_num });
                res[customers[i].idx] = room_num++;
            }
        }
    }
    cout << room_num - 1 << nl;
    for ( int i = 0; i < n; i++ )
    {
        cout << res[i] << " ";
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