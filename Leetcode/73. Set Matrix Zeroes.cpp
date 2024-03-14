#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

void setZeroes(vector<vector<int>> &matrix)
{
    bool zero_first_row = false;
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                if (i == 0)
                {
                    zero_first_row = true;
                }
                else
                {
                    matrix[i][0] = 0;
                }
            }
        }
    }
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < rows; i++)
        {
            matrix[i][0] = 0;
        }
    }
    if (zero_first_row)
    {
        for (int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    }
}
int main()
{
    FastIO;
    int r, c;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    setZeroes(mat);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}