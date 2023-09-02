#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int main()
{
    FastIO;
    int n, m;
    cin >> n >> m;
    multiset<ll> tp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tp.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto p = tp.lower_bound(x + 1);
        if (p == tp.begin())
        {
            cout << -1 << "\n";
        }
        else
        {
            --p;
            cout << *p << "\n";
            tp.erase(p);
        }
    }

    return 0;
}