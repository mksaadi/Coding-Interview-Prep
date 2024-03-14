// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool good(ll x, ll w, ll h, ll n)
{
    // number of rect in horizontal axis = x/w
    // number of rect in vertical axis = x/h
    return ((x / w) * (x / h) >= n);
}
int main()
{
    FastIO;
    ll w, h, n;
    cin >> w >> h >> n;
    ll left = -1; // good(left) is always false
    ll right = 1;
    // make sure good(right) is always true
    while (!good(right, w, h, n))
    {
        right *= 2LL;
    }

    while (left + 1 < right)
    {
        ll mid = left + (right - left) / 2LL;
        if (good(mid, w, h, n))
        {
            right = mid;
        }
        else
            left = mid;
    }
    cout << right << "\n";

    return 0;
}