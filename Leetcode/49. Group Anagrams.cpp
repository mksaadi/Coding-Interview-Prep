#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

// without sorting

// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
//     int n = strs.size();
//     map<string, vector<string>> mp;
//     for (int i = 0; i < strs.size(); i++)
//     {
//         string cnt_str(26, '0');
//         for (int j = 0; j < strs[i].size(); j++)
//         {
//             int idx = strs[i][j] - 'a';
//             cnt_str[idx]++;
//         }
//         mp[cnt_str].push_back(strs[i]);
//     }
//     vector<vector<string>> ans;
//     for (auto m : mp)
//     {
//         vector<string> s;
//         for (int i = 0; i < m.second.size(); i++)
//         {
//             s.push_back(m.second[i]);
//         }
//         ans.push_back(s);
//     }
//     return ans;
// }

// with sorting

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();
    map<string, vector<string>> mp;
    for (int i = 0; i < strs.size(); i++)
    {
        string original = strs[i];
        sort(strs[i].begin(), strs[i].end());
        mp[strs[i]].push_back(original);
    }
    vector<vector<string>> ans;
    for (auto m : mp)
    {
        vector<string> s;
        for (int i = 0; i < m.second.size(); i++)
        {
            s.push_back(m.second[i]);
        }
        ans.push_back(s);
    }
    return ans;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    vector<vector<string>> res = groupAnagrams(strs);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}