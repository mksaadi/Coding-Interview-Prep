#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int minOperations(vector<int> &nums)
{
    int ans = 0;
    map<int, int> freq;
    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
    }
    for (auto i : freq)
    {
        if (i.second == 1)
        {
            return -1;
        }
        int three_op = (i.second / 3);
        if (i.second % 3 == 1)
        {
            three_op--;
        }
        int two_op = (i.second - (three_op * 3)) / 2;
        ans += (three_op + two_op);
    }
    return ans;
}

int main()
{
    FastIO;
    return 0;
}