#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

string convert(string s, int numRows)
{
    int n = s.size();
    char zig[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            zig[i][j] = ' ';
        }
    }
    int idx = 0;
    int row = 0;
    int col = 0;

    while (idx < n)
    {
        while (true)
        {
            if (idx == n)
                break;

            zig[row][col] = s[idx++];
            row++;
            if (row == numRows)
            {
                --row;
                break;
            }
        }
        while (true)
        {

            if(row>0)row--;
            col++;
            if (idx == n)
                break;
            zig[row][col] = s[idx++];

            if (row == 0)
            {
                row++;
                break;
            }
        }
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (zig[i][j] != ' ')
                ans += zig[i][j];
        }
    }
    return ans;
}

int main()
{
    FastIO;
    string s;
    cin >> s;
    cout << convert(s, 1) << "\n";
    return 0;
}