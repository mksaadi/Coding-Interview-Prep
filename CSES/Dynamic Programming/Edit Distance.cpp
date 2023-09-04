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
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    int n = a.size();
    int m = b.size();
    int dp[n][m];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = i + j;
            }
            else
            {
                int k = (a[i] == b[j] ? 0 : 1);
                dp[i][j] = min({dp[i - 1][j - 1] + k, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            }
        }
    }

    cout << dp[n - 1][m - 1] << "\n";

    return 0;
}