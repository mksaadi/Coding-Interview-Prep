#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int search(vector<int> &nums, int target)
{
    int high = nums.size() - 1;
    int low = 0;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    FastIO;
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << search(nums, target) << "\n";

    return 0;
}