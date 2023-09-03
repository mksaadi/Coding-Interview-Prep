#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

const int mod = 1e9 + 7;

int main()
{
    FastIO;
    int n;
    cin >> n;
    char grid[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    int dp[n][n];
    memset(dp, 0, sizeof dp);
    dp[0][0] = (grid[0][0] == '.' ? 1 : 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (grid[i][j] == '.')
            {
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= mod;
                }
                if (j > 0)
                {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= mod;
                }
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}