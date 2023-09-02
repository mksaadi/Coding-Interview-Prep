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
    ll n, m, k;
    cin >> n >> m >> k;
    // solution using sorting and two pointer
    vector<ll> ds(n);
    vector<ll> as(m);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ds[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> as[i];
    }
    sort(ds.begin(), ds.end());
    sort(as.begin(), as.end());
    int l = 0;
    int r = 0;
    while (l < n && r < m)
    {
        if (ds[l] - k > as[r])
        {
            r++;
        }
        else if (ds[l] + k < as[r])
        {
            l++;
        }
        else
        {
            cnt++;
            r++;
            l++;
        }
    }
    cout << cnt << "\n";

    // solution using upperbound and lowerbound with multiset
    // multiset<ll> req_size;
    // multiset<ll> ap_size;
    // for (int i = 0; i < n; i++)
    // {
    //     ll val;
    //     cin >> val;
    //     req_size.insert(val);
    // }
    // for (int i = 0; i < m; i++)
    // {
    //     ll val;
    //     cin >> val;
    //     ap_size.insert(val);
    // }

    // int cnt = 0;
    // for (auto i : req_size)
    // {
    //     auto ap1 = ap_size.lower_bound(i - k);

    //     if (abs(*ap1 - i) <= k)
    //     {
    //         cnt++;
    //         ap_size.erase(ap1);
    //         continue;
    //     }
    //     ap1 = ap_size.upper_bound(i);
    //     if (abs(*ap1 - i) <= k)
    //     {
    //         cnt++;
    //         ap_size.erase(ap1);
    //         continue;
    //     }
    // }
    // cout << cnt << "\n";

    return 0;
}