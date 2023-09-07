#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> ans;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1] ^ arr[i];
    }
    for (auto q : queries)
    {
        int left = q[0];
        int right = q[1];
        ans.push_back((arr[right] ^ (left - 1 >= 0 ? arr[left - 1] : 0)));
    }
    return ans;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        queries[i].push_back(l);
        queries[i].push_back(r);
    }
    vector<int> ans = xorQueries(arr, queries);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << "\n";
    return 0;
}