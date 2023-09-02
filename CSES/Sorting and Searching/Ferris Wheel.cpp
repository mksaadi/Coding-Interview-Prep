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
    ll n, x;
    cin >> n >> x;
    vector<ll> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    int l = 0;
    int r = n - 1;
    int cnt = 0;
    ll cap = x;
    while (l <= r)
    {
        if (l == r)
        {
            cnt++;
            break;
        }
        if (w[l] + w[r] <= cap)
        {
            cnt++;
            l++;
            r--;
        }
        else
        {
            cnt++;
            r--;
        }
    }
    cout << cnt << "\n";

    return 0;
}