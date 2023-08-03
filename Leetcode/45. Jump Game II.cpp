#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int jump(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    int left = 0;
    int right = 0;
    int jumps = 0;
    while (true)
    {
        jumps++;
        int mx = 0;
        for (int i = left; i <= right; i++)
        {
            mx = max(mx, i + nums[i]);
        }
        if (mx >= n - 1)
        {
            cout<<"[ "<< right+1<<", " <<mx<<" ]\n";
            return jumps;
        }
        left = right + 1;
        right = mx;
        cout<<"[ "<< left<<", " <<right<<" ]\n";
    }
    return jumps;
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
    cout << jump(nums) << "\n";
    return 0;
}