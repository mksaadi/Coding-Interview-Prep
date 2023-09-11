#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

void solve()
{
    vector<ll> fib(50);
    fib[0] = 0;
    fib[1] = 1;
    ll sum = 0;
    for (int i = 2; i < 50; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] > 4000000)
        {
            cout << sum << "\n";
            break;
        }
        if (fib[i] % 2 == 0)
            sum += fib[i];
    }
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}