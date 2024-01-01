#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int minOperations(vector<int> &nums, int x)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = sum - x;
    int max_sub_len = -1;
    int left = 0;
    int pref_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pref_sum += nums[i];
        while (pref_sum > target && left <= i)
        {
            pref_sum -= nums[left++];
        }
        if (pref_sum == target)
        {
            max_sub_len = max(max_sub_len, (i - left + 1));
        }
    }
    return (max_sub_len == -1 ? -1 : (n - max_sub_len));
}
int main()
{
    FastIO;
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << minOperations(v, x) << "\n";

    return 0;
}
