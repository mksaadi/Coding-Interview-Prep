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
    int book_num, balance;
    cin >> book_num >> balance;
    vector<int> prices(book_num);
    vector<int> pages(book_num);
    for (int i = 0; i < book_num; i++)
    {
        cin >> prices[i];
    }
    for (int i = 0; i < book_num; i++)
    {
        cin >> pages[i];
    }

    int dp[book_num + 1][balance + 1];
    // dp[i][j] = if there were i books and j were the highest we could spend what is the max page number

    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= book_num; i++)
    {
        for (int j = 1; j <= balance; j++)
        {
            if (j >= prices[i - 1])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[book_num][balance] << "\n";
    return 0;
}