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
    int l = -1; // bigger than nums[0]
    int r = n;  // smaller than nums[0]
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] < nums[0])
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


int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int k = find_k(nums);
    cout << "K = " << k << "\n";
    int rotating_factor = k % n;
    cout << "Rotating Factor =  " << rotating_factor << "\n";
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int r_mid = (mid + rotating_factor) % n;
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