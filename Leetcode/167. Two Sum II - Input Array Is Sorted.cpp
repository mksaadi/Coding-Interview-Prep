#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

vector<int> twoSum(vector<int> &v, int target)
{

    int l = 0;
    int r = v.size();
    --r;
    vector<int> res(2);
    while (l < r)
    {
        if (v[l] + v[r] == target)
        {

            res[0] = l + 1;
            res[1] = r + 1;
            return res;
        }
        else if (v[l] + v[r] > target)
        {
            --r;
        }
        else
        {
            l++;
        }
    }
    return res;
}
int main()
{
    FastIO;
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> res = twoSum(v, t);
    cout << res[0] << " " << res[1] << "\n";

    return 0;
}