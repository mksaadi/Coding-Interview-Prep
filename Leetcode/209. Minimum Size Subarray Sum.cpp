#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int l = 0;
    int ans = n + 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        while (sum >= target)
        {
            sum -= nums[l];
            ans = min(ans, i - l + 1);
            l++;
        }
    }
    return (ans == n + 1 ? 0 : ans);
}

int main()
{
    FastIO;
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << minSubArrayLen(t, nums) << "\n";

    return 0;
}