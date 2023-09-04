#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int hi = x;
    int lo = 1;
    while (lo + 1 < hi)
    {
        int mid = (lo + (hi - lo) / 2);
        // mid*mid <= x
        //== mid <= x/mid (avoid overflow)
        if (mid <= x / mid)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    return lo;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    cout << mySqrt(n) << "\n";
    return 0;
}