#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

vector<vector<int>> findMatrix(vector<int> &nums)
{
    map<int, int> freq;
    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); i++)
    {
        if (freq[nums[i]] >= res.size())
        {
            res.push_back({});
        }
        res[freq[nums[i]]].push_back(nums[i]);
        freq[nums[i]]++;
    }
    return res;
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
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    vector<vector<int>> res = findMatrix(v);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (j + 1 == res[i].size())
            {
                cout << "]";
            }
            else
            {
                cout << ",";
            }
        }
        if (i + 1 < res.size())
        {
            cout << ",";
        }
    }
    cout << "]";

    return 0;
}