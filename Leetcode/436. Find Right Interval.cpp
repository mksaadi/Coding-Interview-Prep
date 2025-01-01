// https://leetcode.com/problems/find-right-interval/description/?envType=study-plan-v2&envId=binary-search

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int find_leftmost_start(int end_i, vector<vector<int>> &intervals)
{
    int l = -1;
    int r = intervals.size();
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        if (intervals[mid][0] >= end_i)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if (r == intervals.size())
    {
        return -1;
    }
    return r;
}
int main()
{
    FastIO;
    int sz;
    cin >> sz;
    vector<vector<int>> intervals(sz, vector<int>(2));
    for (int i = 0; i < sz; i++)
    {
        int l, r;
        cin >> l >> r;
        intervals[i][0] = l;
        intervals[i][1] = r;
    }
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        // find the right interval of intervals[0] = [3,4]
        // find the leftmost intervals where start_j >= 4
        res.push_back(find_leftmost_start(intervals[i][1], intervals));
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << nl;
    return 0;
}