#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int coinChange(vector<int> &coins, int amount)
{
    const int inf = 1e9;
    vector<int> dp(amount + 5, inf);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (auto c : coins)
        {
            if (i - c >= 0)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return (dp[amount] == inf ? -1 : dp[amount]);
}
int main()
{
    FastIO;
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << coinChange(coins, amount);

    return 0;
}