#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool isPossible(ll t, ll x, ll y, ll n)
{
    // how many copies can they make in t time ?
    // machine 1 makes t/x copies
    // machine 2 makes t/y copies
    // but min(x,y) will be needed for the first copy
    t -= (min(x, y));
    if (t < 0)
        return false;
    n--;
    return (t / x) + (t / y) >= n;
}
int main()
{
    FastIO;
    ll n, x, y;
    cin >> n >> x >> y;
    ll left = 0; // impossible in 0 seconds
    ll right = 1;
    while (!isPossible(right, x, y, n))
    {
        right *= 2;
    }
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (isPossible(mid, x, y, n))
        {
            right = mid;
        }
        else
            left = mid;
    }
    cout << right << "\n";
    return 0;
}