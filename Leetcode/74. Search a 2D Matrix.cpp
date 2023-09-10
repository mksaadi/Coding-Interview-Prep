#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int l = -1;
    int r = (matrix.size());
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (matrix[mid][0] <= target)
        {
            l = mid;
        }
        else
            r = mid;
    }
    if (l == -1)
    {
        return false;
    }

    int low = 0;
    int high = matrix[l].size();
    high--;
    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (matrix[l][mid] == target)
        {
            return true;
        }
        else if (matrix[l][mid] > target)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return false;
}
int main()
{
    FastIO;
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << (searchMatrix(matrix, t) == 1 ? "True\n" : "False\n") << "\n";

    return 0;
}