#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()

//https://leetcode.com/problems/shift-2d-grid/
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    vector<int> v;
    for ( auto& row : grid ) {
        v.insert(v.end(), row.begin(), row.end());
    }
    int n = v.size();
    int start_idx = n - ( k % n );
    for ( int i = 0; i < grid.size(); i++ ) {
        for ( int j = 0; j < grid[0].size(); j++ ) {
            start_idx %= n;
            grid[i][j] = v[start_idx++];
        }
    }
    return grid;
}



int main()
{
    FastIO;
    int row, col, k;
    cin >> row >> col >> k;
    vector<vector<int>>grid(row, vector<int>(col));
    for ( int i = 0; i < row; i++ )
    {
        for ( int j = 0; j < col; j++ )
        {
            cin >> grid[i][j];
        }
    }

    grid = shiftGrid(grid, k);
    for ( int i = 0; i < row; i++ )
    {
        for ( int j = 0; j < col; j++ )
        {
            cout << grid[i][j] << " ";
        }
        cout << nl;
    }


    return 0;
}