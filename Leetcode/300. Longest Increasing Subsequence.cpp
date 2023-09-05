#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

// N*N solution
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max_length = 0;
    for (int i = 0; i < n; i++)
    {
        max_length = max(max_length, dp[i]);
    }

    return max_length;
}

// N * log(N) Solution
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> piles;

    for (int i = 0; i < n; i++)
    {
        int left = 0, right = piles.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (piles[mid] < nums[i])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (left == piles.size())
        {
            piles.push_back(nums[i]);
        }
        else
        {
            piles[left] = nums[i];
        }
    }

    return piles.size();
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << lengthOfLIS(nums);
    return 0;
}