#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool ok(int x)
{
    string s = to_string(x);
    int n = s.size();
    if (n & 1)
    {
        return false;
    }
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n / 2; i++)
    {
        sum1 += (s[i] + '0');
    }
    for (int i = n / 2; i < n; i++)
    {
        sum2 += (s[i] + '0');
    }
    return sum1 == sum2;
}

int countSymmetricIntegers(int low, int high)
{
    int cnt = 0;
    for (int i = low; i <= high; i++)
    {
        if (ok(i))
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    FastIO;
    int high, low;
    cin >> high >> low;
    cout << countSymmetricIntegers(high, low);
    return 0;
}