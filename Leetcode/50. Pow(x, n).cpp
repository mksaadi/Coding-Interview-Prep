#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
long long mod = 1e9 + 7;

double myPowPal(double x, long n)
{

    if (n == 0)
        return 1.00000;
    if (n < 0)
        return 1 / myPowPal(x, -n);
    double u = myPowPal(x, n / 2);
    u = (u * u);
    if (n % 2 == 1)
        u = (u * x);
    return u;
}
double myPow(double x, int n)
{
    return myPowPal(x, n);
}

int main()
{
    FastIO;
    cout.setf(std::ios::fixed, std::ios::floatfield);
    cout.precision(5);
    double x;
    int n;
    cin >> x;
    cin >> n;
    cout << myPow(x, n) << "\n";
    return 0;
}