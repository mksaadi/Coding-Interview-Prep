#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

// Clean solution
bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c && i != row)
            return false;
        if (board[row][i] == c && i != col)
            return false;
        int sub_row = 3 * (row / 3) + (i / 3);
        int sub_col = 3 * (col / 3) + (i % 3);
        if (board[sub_row][sub_col] == c && sub_row != row && sub_col != col)
            return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                if (!isValid(board, i, j, board[i][j]))
                    return false;
            }
        }
    }
    return true;
}
// My solution
// bool isValidSudoku(vector<vector<char>> &board)
// {
//     map<pair<int, int>, bool> seen_in_col;
//     map<pair<int, int>, bool> seen_in_row;
//     map<vector<int>, bool> seen_in_sub_matrix;
//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             if (board[i][j] != '.')
//             {
//                 if (seen_in_row[{i, int(board[i][j] - '0')}])
//                 {
//                     return false;
//                 }
//                 seen_in_row[{i, int(board[i][j] - '0')}] = true;
//                 if (seen_in_col[{j, int(board[i][j] - '0')}])
//                 {
//                     return false;

//                 }
//                 seen_in_col[{j, int(board[i][j] - '0')}] = true;
//                 int sub_row = i / 3;
//                 int sub_col = j / 3;
//                 if (seen_in_sub_matrix[{sub_row, sub_col, int(board[i][j] - '0')}])
//                 {
//                     return false;
//                 }
//                 seen_in_sub_matrix[{sub_row, sub_col, int(board[i][j] - '0')}] = true;
//             }
//         }
//     }
//     return true;
// }

int main()
{
    FastIO;
    vector<vector<char>> matrix(9, vector<char>(9));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> matrix[i][j];
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}