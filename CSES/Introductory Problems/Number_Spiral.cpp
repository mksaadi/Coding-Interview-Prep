#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(ll x, ll y)
{
    if (x % 2LL == 0LL && y <= x)
    {
        cout << (x * x) - (y - 1LL) << "\n";
        return;
    }
    if (y & 1LL && x <= y)
    {
        cout << (y * y) - (x - 1LL) << "\n";
        return;
    }
    if (x & 1LL && y <= x)
    {

        cout << ((x - 1LL) * (x - 1LL)) + y << "\n";
        return;
    }
    if (y % 2LL == 0LL && x <= y)
    {
        cout << ((y - 1LL) * (y - 1LL)) + x << "\n";
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}