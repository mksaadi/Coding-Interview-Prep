#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
int main()
{
    FastIO;
    int n, c;
    cin >> c >> n;
    vector<int> coins(c);
    for (int i = 0; i < c; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (auto coin : coins)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i - coin >= 0)
            {
                dp[i] += dp[i - coin];
                dp[i] %= mod;
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}