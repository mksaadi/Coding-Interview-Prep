#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int minDistance(string str1, string str2)
{
    str1 = " " + str1;
    str2 = " " + str2;
    int n = str1.size();
    int m = str2.size();
    int dp[n][m];
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
                int k = (str1[i] == str2[j] ? 0 : 1);
                dp[i][j] = min({dp[i - 1][j - 1] + k, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            }
        }
    }
    return dp[n - 1][m - 1];
}
int main()
{
    FastIO;
    string str1, str2;
    cin >> str1 >> str2;
    cout << minDistance(str1, str2) << "\n";
    return 0;
}