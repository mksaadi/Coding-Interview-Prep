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
    vector<int> dice = {1, 2, 3, 4, 5, 6};
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (auto d : dice)
        {
            if (i - d >= 0)
            {
                dp[i] += dp[i - d];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n] << "\n";

    return 0;
}