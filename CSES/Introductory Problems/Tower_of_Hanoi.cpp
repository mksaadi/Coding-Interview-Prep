#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

vector<pair<int, int>> moves;

void toh(int n, int first, int middle, int last)
{
    if (n == 0)
        return;
    toh(n - 1, first, last, middle);
    moves.emplace_back(first, last);
    toh(n - 1, middle, first, last);
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    toh(n, 1, 2, 3);
    cout << (1 << n) - 1 << "\n";
    for (auto i : moves)
    {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}