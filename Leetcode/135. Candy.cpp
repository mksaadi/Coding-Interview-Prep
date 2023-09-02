#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define print(v)          \
    for (auto x : v)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << "\n";

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    int sum = 0;
    if (n == 1)
    {
        return 1;
    }
    int total = n;
    vector<int> candies(n, 1);
    // comparing to the left neighbour
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        sum += candies[i];
    }
    // print(ratings);
    // print(candies);
    // int sum = accumulate(candies.begin(), candies.end(), 0);
    sum += candies[n - 1];
    return sum;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ratings[i];
    }
    cout << candy(ratings) << "\n";
    return 0;
}