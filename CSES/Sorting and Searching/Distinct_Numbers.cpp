#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int main()
{
    FastIO;
    int n;
    cin >> n;
    // using map
    int cnt = 0;
    map<int, bool> seen;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!seen[x])
        {
            seen[x] = true;
            cnt++;
        }
    }
    cout << cnt << nl;
    // using sorting
    // vector<int> v(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    // }
    // sort(v.begin(), v.end());
    // int cnt = 1;
    // for (int i = 1; i < n; i++)
    // {
    //     if (v[i] != v[i - 1])
    //         cnt++;
    // }
    // cout << cnt << "\n";
    return 0;
}