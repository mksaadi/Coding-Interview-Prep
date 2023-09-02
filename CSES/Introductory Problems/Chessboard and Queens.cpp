#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int cnt = 0;
vector<string> board(8);
vector<bool> col(8, false);
vector<bool> diag1(15, false);
vector<bool> diag2(15, false);

void backtrack(int y)
{
    if (y == 8)
    {
        cnt++;
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            if (board[y][i] == '*' || col[i] || diag1[i + y] || diag2[i - y + 7])
            {
                continue;
            }
            col[i] = diag1[i + y] = diag2[i - y + 7] = 1;
            backtrack(y + 1);
            col[i] = diag1[i + y] = diag2[i - y + 7] = 0;
        }
    }
}

int main()
{
    FastIO;

    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }
    backtrack(0);
    cout << cnt << "\n";

    return 0;
}