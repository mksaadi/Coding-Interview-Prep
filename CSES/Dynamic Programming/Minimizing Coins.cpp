#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

const int inf = 1e9 + 5;
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
    vector<int> dp(n + 1, inf);

    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto c : coins)
        {
            if (i - c >= 0)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    cout << (dp[n] == inf ? -1 : dp[n]) << "\n";

    return 0;
}