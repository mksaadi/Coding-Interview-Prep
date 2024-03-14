// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

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
        else
        {
            l = mid;
        }
    }

    return l + 1;
}
int main()
{
    FastIO;
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
    cout << searchInsert(v, target);
    return 0;
}