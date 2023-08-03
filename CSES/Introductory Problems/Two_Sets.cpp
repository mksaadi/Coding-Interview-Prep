#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using ld = long double;
#define ff first
#define nl "\n"
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define print(v)          \
    for (auto x : v)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << "\n";
const long long INF = 2000000000000000000LL;
const long double EPS = 1e-9;
const long long mod = 1e9 + 7;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define set_precision(x)                              \
    cout.setf(std::ios::fixed, std::ios::floatfield); \
    cout.precision(x);

void solve(ll n)
{
    ll sum = (n * (n + 1LL)) / 2LL;

    if (sum & 1LL)
    {
        cout << "NO\n";
        return;
    }
    ll half = sum / 2LL;

    vl set1, set2;
    map<ll, bool> taken;
    ll cur_sum = 0;
    for (ll i = n; i >= 1; i--)
    {
        if (cur_sum + i <= (half))
        {
            taken[i] = 1;
            cur_sum += i;
            set1.push_back(i);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!taken[i])
            set2.push_back(i);
    }
    cout << "YES\n";
    cout << set1.size() << "\n";
    print(set1);
    cout << set2.size() << "\n";
    print(set2);
}

int main()
{
    FastIO;
    ll t;
    cin >> t;

    solve(t);

    return 0;
}