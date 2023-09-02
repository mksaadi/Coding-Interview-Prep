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
    ll n;
    ll sum = 0LL;
    cin >> n;
    vector<ll> apples(n);
    for (int i = 0; i < n; i++)
    {
        cin >> apples[i];
        sum += apples[i];
    }

    ll ans = 1e9;

    for (int i = 0; i < (1 << n); i++)
    {
        ll sub_sum = 0LL;
        for (int j = 0; j < n; j++)
        {

            if (i & (1 << j))
            {
                sub_sum += apples[j];
            }
        }
        ll rem = sum - sub_sum;
        ll dif = abs(sub_sum - rem);
        ans = min(ans, dif);
    }
    cout << ans << nl;

    return 0;
}