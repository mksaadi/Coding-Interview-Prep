#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

uint32_t reverseBits(uint32_t n)
{

    uint32_t res = 0;
    for (uint32_t i = 0; i < 32; i++)
    {
        if (n & ((uint32_t)1 << i))
        {
            res += ((uint32_t)1 << (31 - i));
        }
    }
    return res;
}

int main()
{
    FastIO;
    uint32_t n;
    cin >> n;
    cout << reverseBits(n) << "\n";
    return 0;
}