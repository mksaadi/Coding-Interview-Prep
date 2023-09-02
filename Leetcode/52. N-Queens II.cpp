#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int cnt = 0;

void placeQueen(int y, int n, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2)
{
    if (y == n)
    {
        cnt++;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (cols[i] || diag1[i + y] || diag2[i - y + n - 1])
                continue;
            cols[i] = diag1[i + y] = diag2[i - y + n - 1] = true;
            placeQueen(y + 1, n,cols,diag1,diag2);
            cols[i] = diag1[i + y] = diag2[i - y + n - 1] = false;
        }
    }
}
int totalNQueens(int n)
{
    vector<bool> cols(10, false);
    vector<bool> diag1(20, false);
    vector<bool> diag2(20, false);

    placeQueen(0, n,cols,diag1,diag2);
    return cnt;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    cout << totalNQueens(n) << "\n";
    return 0;
}