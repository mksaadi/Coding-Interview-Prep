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
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define print(v)          \
    for (auto x : v)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << endl;                            // print the vector
const long long INF = 2000000000000000000LL; // 2e18
const long double EPS = 1e-9;
const long long mod = 1e9 + 7;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// cout.setf( std::ios::fixed, std:: ios::floatfield );               // floatfield not set
// cout.precision(10);

void print_map(map<char, char> mp)
{
    for (auto x : mp)
    {
        cout << x.first << " " << x.second << "\n";
    }
}

bool isIsomorphic(string s, string t)
{
    map<char, char> st;
    map<char, char> ts;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.find(s[i]) != st.end() && st[s[i]] != t[i])
            return false;
        st[s[i]] = t[i];
        if (ts.find(t[i]) != ts.end() && ts[t[i]] != s[i])
            return false;
        ts[t[i]] = s[i];
    }

    return true;
}

int main()
{
    FastIO;
    string s, t;
    cin >> s >> t;
    if (isIsomorphic(s, t))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}