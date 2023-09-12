#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int findLeft(vector<int> &nums, int target)
{
    // find the leftmost index that is equal to target
    int l = -1;               // always less than target
    int r = (int)nums.size(); // greater or equal to target
    // now reduce r as much as possible
    while (l + 1 < r)
    {
        int mid = l + ((r - l) / 2);
        if (nums[mid] >= target)
        {
            r = mid;
        }
        else
            l = mid;
    }
    if (r >= (int)nums.size() || nums[r] != target)
    {
        return -1;
    }
    return r;
}
int findRight(vector<int> &nums, int target)
{
    // find the rightmost index that is equal to
    int l = -1;               // always less or equal to target
    int r = (int)nums.size(); // greater than target
    // increase l as much as possible
    while (l + 1 < r)
    {
        int mid = l + ((r - l) / 2);
        if (nums[mid] <= target)
        {
            l = mid;
        }
        else
            r = mid;
    }
    if (l == -1 || nums[l] != target)
        return -1;
    return l;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    return {findLeft(nums, target), findRight(nums, target)};
}

int main()
{
    FastIO;
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> ans = searchRange(v, target);
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}