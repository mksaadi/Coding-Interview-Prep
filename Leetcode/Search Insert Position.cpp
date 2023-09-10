#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    // short answer useing library
    // auto lb = lower_bound(nums.begin(),nums.end(),target);
    // return (lb-nums.begin());

    // general binary search
    // just remember to add 1 to l after bin search.
    int l = -1;          // arr[l] is always less than or equal target
    int r = nums.size(); // arr[r] is always greater than target
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
        {
            r = mid;
        }
        else if (nums[mid] < target)
        {
            l = mid;
        }
    }

    return l + 1;
}
int main()
{
    vector<int> arr = {1, 3, 5, 6};
    int target = 5;
    cout << searchInsert(arr, target) << "\n";

    return 0;
}