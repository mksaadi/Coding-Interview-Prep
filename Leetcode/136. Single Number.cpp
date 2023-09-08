#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int singleNumber(vector<int> &nums)
{
    int x = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        x ^= nums[i];
    }
    return x;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << singleNumber(v) << "\n";
    return 0;
}