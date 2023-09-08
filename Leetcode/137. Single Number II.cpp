#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

// approach 1: O(N) (my solution)
// int singleNumber(vector<int> &nums)
// {
//     int ans = 0;
//     for (int i = 0; i < 32; i++)
//     {
//         int bit_sum = 0;
//         for (int j = 0; j < nums.size(); j++)
//         {
//             if (nums[j] & (1 << i))
//             {
//                 bit_sum++;
//                 bit_sum %= 3;
//             }
//         }
//         ans += (bit_sum << i);
//     }
//     return ans;
// }

// approach 2 : optimal solution

int singleNumber(vector<int> &nums)
{
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ones = (ones ^ nums[i]) & (~twos);
        twos = (twos ^ nums[i]) & (~ones);
    }
    return ones;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << singleNumber(v) << '\n';
    return 0;
}