#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()


int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int idx = 1;
    for (int i = 1; i < n; i++)
    {
        if(nums[i-1] != nums[i])
        {
            nums[idx++] = nums[i];
        }
    }
    return idx;
}

int main()
{
    FastIO;
    return 0;
}