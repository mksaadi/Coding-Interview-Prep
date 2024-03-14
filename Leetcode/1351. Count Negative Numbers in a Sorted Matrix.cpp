// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int countNegatives(vector<vector<int>> &grid)
{
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        auto lb = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
        ans += lb - grid[i].rbegin();
    }
    return ans;
}

int main()
{
    FastIO;
    int n, m;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << countNegatives(v) << "\n";
    return 0;
}