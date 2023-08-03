#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0 || n == 1)
        return;
    vector<int> dup(n);
    for (int i = 0; i < n; i++)
    {
        dup[i] = nums[(i + k) % n];
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = dup[i];
    }
}   

int main()
{
    FastIO;
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    rotate(v, k);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}