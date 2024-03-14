#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool isBadVersion(int m)
{
    // provided by leetcode
    return false;
}

int firstBadVersion(int n)
{
    int left = 0;        // definitely good
    int right = INT_MAX; // definitely bad
    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return left + 1;
}
int main()
{
    FastIO;
  
    return 0;
}