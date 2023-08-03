#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int cur_price = prices[0];
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (prices[i] > cur_price)
        {
            profit += (prices[i] - cur_price);
        }
        cur_price = prices[i];
    }
    return profit;
}

int main()
{
    FastIO;
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    cout<<maxProfit(prices)<<"\n";
    return 0;
}