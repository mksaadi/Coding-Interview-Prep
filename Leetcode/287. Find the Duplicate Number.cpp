#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int findDuplicate(vector<int> &nums)
{
    int fast = 0;
    int slow = 0;
    while (1)
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
        if (fast == slow)
            break;
    }
    int sslow = 0;
    while (1)
    {
        sslow = nums[sslow];
        slow = nums[slow];
        if (sslow == slow)
        {
            break;
        }
    }
    return slow;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << findDuplicate(nums) << '\n';
    return 0;
}