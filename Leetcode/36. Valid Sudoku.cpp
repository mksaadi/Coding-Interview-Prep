#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool isValidSudoku(vector<vector<char>> &board)
{
    //TBD
}

int main()
{
    FastIO;
    vector<vector<int>> matrix(9, vector<int>(9));
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