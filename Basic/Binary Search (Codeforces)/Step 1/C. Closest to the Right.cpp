//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C

// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int binSearch(vector<ll> &v, ll target)
{
    ll left = -1;        // v[left] will always be smaller
    ll right = v.size(); // v[right] will always be greater or equal

    while (right > left + 1)
    {
        ll mid = left + (right - left) / 2;
        if (v[mid] < target)
            left = mid;
        else
            right = mid;
    }
    return right + 1;
}

int main()
{
    FastIO;
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<ll> q(k);
    for (int i = 0; i < k; i++)
    {
        cin >> q[i];
        cout << binSearch(v, q[i]) << '\n';
    }

    return 0;
}