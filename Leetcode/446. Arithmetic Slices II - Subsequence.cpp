#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    vector<unordered_map<int, int>> dp(n);
    unordered_map<long long, vector<int>> pos;
    for (int i = 0; i < n; i++)
    {
        pos[nums[i]].push_back(i);
    }

    function<int(int, long long)> helper;

    helper = [&dp, &pos, &nums, &helper](int p, long long dx) -> int
    {
        if (dp[p].count(dx))
        {
            return dp[p][dx];
        }
        dp[p][dx] = 1;
        long long need = nums[p] + dx;
        int next = lower_bound(pos[need].begin(), pos[need].end(), p + 1) - pos[need].begin();
        for (int i = next; i < pos[need].size(); i++)
        {
            dp[p][dx] += helper(pos[need][i], dx);
        }
        return dp[p][dx];
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans += helper(j, (long long)nums[j] - (long long)nums[i]) - 1;
        }
    }

    return ans;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << numberOfArithmeticSlices(nums) << "\n";
    return 0;
}
