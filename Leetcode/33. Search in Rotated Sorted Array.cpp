#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int find_k(vector<int> &nums)
{
    int n = nums.size();
    int l = 0; // bigger than nums[0]
    int r = n; // smaller than nums[0]
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] < nums[0])
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int k = find_k(nums);

    int l = 0;
    int r = n - 1;
    int rf = (k % n);
    while (l <= r)
    {
        int mid = (l + r + 1) / 2;
        int r_mid = (mid + rf) % n;
        if (nums[r_mid] == target)
        {
            return r_mid;
        }
        else if (nums[r_mid] > target)
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
    FastIO;
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << search(v, target);
    return 0;
}