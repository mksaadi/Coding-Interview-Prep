#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll mulSum(int n, int k)
{

    ll p = n / k;
    ll sum = (ll)k * (((ll)p * (p + 1)) / 2LL);
    return sum;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        ll res = mulSum(n - 1, 3) + mulSum(n - 1, 5) - mulSum(n - 1, 15);
        cout << res << "\n";
    }

    return 0;
}