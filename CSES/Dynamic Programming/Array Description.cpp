#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
const ll mod = 1e9 + 7;

int main()
{
    FastIO;
    ll n, m;
    cin >> n >> m;

    vector<ll> x(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    ll dp[n + 2][m + 2];
    memset(dp, 0LL, sizeof dp);

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (x[i] == 0 || x[i] == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else
            {
                if (x[i] == 0 || x[i] == j)
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
                }
                else
                    dp[i][j] = 0;
            }
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= m; i++)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans << nl;

    return 0;
}
