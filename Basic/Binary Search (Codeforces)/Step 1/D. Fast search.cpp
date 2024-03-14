// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int leftMost(vector<ll> &v, ll target)
{
    // find the leftmost index which has the value greater or equal to l

    ll left = -1;        // v[left] is smaller than target
    ll right = v.size(); // v[right] is greater than or equal to target

    while (right > left + 1)
    {
        ll mid = left + (right - left) / 2;
        if (v[mid] >= target)
            right = mid;
        else
            left = mid;
    }
    return right + 1;
}
int rightMost(vector<ll> &v, ll target)
{
    // find the right most index which has the value samller or equal to r

    ll left = -1;        // v[left] will always be smaller or equal
    ll right = v.size(); // v[right] will always be greater

    while (right > left + 1)
    {
        ll mid = left + (right - left) / 2;
        if (v[mid] <= target)
            left = mid;
        else
            right = mid;
    }
    return left + 1;
}

int main()
{
    FastIO;
    ll n, k;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(all(v));

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        int lb = leftMost(v, l);
        int up = rightMost(v, r);
        cout << (up - lb) + 1 << " ";
    }

    return 0;
}