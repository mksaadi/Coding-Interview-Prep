#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int maxFrequencyElements(vector<int> &nums)
{
    vector<int> freq(102, 0);
    int max_freq = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
        max_freq = max(max_freq, freq[nums[i]]);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq[nums[i]] == max_freq)
        {
            res++;
        }
    }
    return res;
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
    cout << maxFrequencyElements(nums) << "\n";
    return 0;
}