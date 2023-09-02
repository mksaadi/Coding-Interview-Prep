#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
const int inf = 1e9;
vector<int> digits(int n)
{
    vector<int> res;
    while (n > 0)
    {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int> digs = digits(i);
        for (auto d : digs)
        {
            if (i - d >= 0)
            {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}