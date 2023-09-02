#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
// with extra memory
// vector<int> productExceptSelf(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> res(n);
//     vector<int> pref(n);
//     vector<int> post(n);
//     pref[0] = nums[0];
//     post[n - 1] = nums[n - 1];
//     for (int i = 1; i < n; i++)
//     {
//         pref[i] = pref[i - 1] * nums[i];
//     }
//     for (int i = n - 2; i >= 0; i--)
//     {
//         post[i] = post[i + 1] * nums[i];
//     }

//     res[0] = post[1];
//     res[n - 1] = pref[n - 2];
//     for (int i = 1; i < n - 1; i++)
//     {
//         res[i] = pref[i - 1] * post[i + 1];
//     }
//     return res;
// }
// // without extra memeory
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);
    int pref = 1;
    for (int i = 0; i < n; i++)
    {
        res[i] = pref;
        pref *= nums[i];
    }
    int post = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        res[i] *= post;
        post *= nums[i];
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
    vector<int> res = productExceptSelf(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}