#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int trailingZeroes(int n)
{
    int res = 0;
    while (n > 0)
    {
        res += (n / 5);
        n /= 5;
    }
    return res;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    cout << n << "! has " << trailingZeroes(n) << " trailing zeros.\n";
    return 0;
}