#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll row, ll col)
{
    ll ans;
    /// if row is even number and col<=row
    if (row % 2 == 0 && col <= row)
    {
        ans = (row * row) - col + 1;
        return ans;
    }
    /// if col is odd and row<=col
    else if (col % 2 == 1 && row <= col)
    {
        ans = (col * col) - row + 1;
        return ans;
    }
    /// if col is even
    else if (col % 2 == 0 && row <= col)
    {
        ans = ((col - 1) * (col - 1)) + row;
        return ans;
    }
    else if (row % 2 == 1 && col <= row)
    {
        ans = ((row - 1) * (row - 1)) + col;
        return ans;
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
        cout << solve(x, y) << "\n";
    }
    return 0;
}