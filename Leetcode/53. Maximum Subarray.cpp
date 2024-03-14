#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
int maxSubArray(vector<int> &nums)
{

    int max_sum = -1e6;
    int sum = -1e6;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = max(nums[i], sum + nums[i]);
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << maxSubArray(v) << "\n";
    return 0;
}