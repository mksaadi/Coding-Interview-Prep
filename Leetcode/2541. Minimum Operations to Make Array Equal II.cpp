#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
{
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        cout << minOperations(a, b, k);
    }
    return 0;
}