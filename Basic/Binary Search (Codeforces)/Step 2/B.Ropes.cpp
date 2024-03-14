//  https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define set_precision(x)                              \
    cout.setf(std::ios::fixed, std::ios::floatfield); \
    cout.precision(x);

bool good(double x, vector<int> &ropes, int k)
{
    int p = 0;
    for (int i = 0; i < ropes.size(); i++)
    {
        p += (floor(ropes[i] / x));
    }
    return (p >= k);
}
int main()
{
    FastIO;
    set_precision(9);
    int n, k;
    cin >> n >> k;
    vector<int> ropes(n);
    for (int i = 0; i < n; i++)
        cin >> ropes[i];

    double l = 0.0;                      // good(l) = true
    double r = *max_element(all(ropes)); // good(r) = false

    for (int i = 0; i < 100; i++)
    {
        double mid = (l + r) / 2.0;
        if (good(mid, ropes, k))
        {
            l = mid;
        }
        else
            r = mid;
    }
    cout << l << "\n";

    return 0;
}