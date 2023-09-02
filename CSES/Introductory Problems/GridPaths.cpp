#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
bool visited[7][7];
int path_count = 0;
string str;

bool isEmpty(int row, int col)
{
    return (row < 7) && (row >= 0) && (col < 7) && (col >= 0) && (!visited[row][col]);
}

void findPaths(int row, int col, int step = 0)
{
    if (row == 6 && col == 0)
    {
        if (step == 48)
        {
            path_count++;
            return;
        }
        return;
    }
    visited[row][col] = true;

    if (str[step] == '?' || str[step] == 'L')
    {
        if (col && !visited[row][col - 1])
        {
            if (!(!isEmpty(row, col - 2) && isEmpty(row + 1, col - 1) && isEmpty(row - 1, col - 1)))
            {
                findPaths(row, col - 1, step + 1);
            }
        }
    }

    if (str[step] == '?' || str[step] == 'R')
    {
        if (col < 6 && !visited[row][col + 1])
        {
            if (!(!isEmpty(row, col + 2) && isEmpty(row + 1, col + 1) && isEmpty(row - 1, col + 1)))
            {
                findPaths(row, col + 1, step + 1);
            }
        }
    }

    if (str[step] == '?' || str[step] == 'U')
    {
        if (row && !visited[row - 1][col])
        {
            if (!(!isEmpty(row - 2, col) && isEmpty(row - 1, col + 1) && isEmpty(row - 1, col - 1)))
            {
                findPaths(row - 1, col, step + 1);
            }
        }
    }

    if (str[step] == '?' || str[step] == 'D')
    {
        if (row < 6 && !visited[row + 1][col])
        {
            if (!(!isEmpty(row + 2, col) && isEmpty(row + 1, col + 1) && isEmpty(row + 1, col - 1)))
            {
                findPaths(row + 1, col, step + 1);
            }
        }
    }

    visited[row][col] = false;
}

int main()
{
    FastIO;
    cin >> str;
    findPaths(0, 0);
    cout << path_count << "\n";
    return 0;
}