#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        vp[i].first = nums[i];
        vp[i].second = i;
    }
    sort(vp.begin(), vp.end());
    for (int i = 1; i < n; i++)
    {
        if (vp[i].first == vp[i - 1].first && abs(vp[i].second - vp[i - 1].second) <= k)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    FastIO;

    return 0;
}