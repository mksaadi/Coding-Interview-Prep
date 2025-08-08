#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()

// solution 
//https://leetcode.com/problems/transpose-matrix/
vector<vector<int>> transpose(vector<vector<int>>& matrix)
{
    vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size()));
    for ( int i = 0; i < matrix[0].size(); i++ )
    {
        for ( int j = 0; j < matrix.size(); j++ ) {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}

int main()
{
    FastIO;
    int row, col;
    cin >> row >> col;
    vector<vector<int>>matrix(row, vector<int>(col));
    for ( int i = 0; i < row; i++ )
    {
        for ( int j = 0; j < col; j++ )
        {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>>res = transpose(matrix);
    for ( int i = 0; i < res.size(); i++ )
    {
        for ( int j = 0; j < res[0].size(); j++ )
        {
            cout << res[i][j] << " ";
        }
        cout << nl;
    }


    return 0;
}