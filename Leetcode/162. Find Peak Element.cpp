#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int findPeakElement(vector<int> &nums)
{
    int l = 0;
    int r = nums.size();
    r--;
    while (l < r)
    {
        int mid = (l + (r - l + 1) / 2);
        if (nums[mid - 1] > nums[mid])
        {
            r = mid - 1;
        }
        else
            l = mid;
    }
    return l;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    vector<int> v(t);
    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
    }
    cout << findPeakElement(v) << "\n";
    return 0;
}