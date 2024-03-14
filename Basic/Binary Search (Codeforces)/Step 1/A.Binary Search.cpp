//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool binSearch(vector<ll> &v, ll target)
{
    ll left = 0;
    ll right = v.size();
    right--;

    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (v[mid] == target)
            return true;
        else if (v[mid] > target)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return false;
}

int main()
{
    FastIO;
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(all(v));
    vector<ll> q(k);
    for (int i = 0; i < k; i++)
    {
        cin >> q[i];
        cout << (binSearch(v, q[i]) ? "YES" : "NO") << '\n';
    }

    return 0;
}