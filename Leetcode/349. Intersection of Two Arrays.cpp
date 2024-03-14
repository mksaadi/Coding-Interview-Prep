// https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

// sorting and two pointers
// (n.log(n) * m.log(m))

// vector<int> intersection(vector<int> &a, vector<int> &b)
// {
//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());
//     a.erase(unique(a.begin(), a.end()), a.end());
//     b.erase(unique(b.begin(), b.end()), b.end());
//     vector<int> ans;
//     int idx1 = 0;
//     int idx2 = 0;
//     while (idx1 < a.size() && idx2 < b.size())
//     {
//         if (a[idx1] == b[idx2])
//         {
//             ans.push_back(a[idx1]);
//             idx1++;
//             idx2++;
//         }
//         else
//         {
//             if (a[idx1] < b[idx2])
//                 idx1++;
//             else
//                 idx2++;
//         }
//     }
//     return ans;
// }

// one map solution
// avg for unordered_map is O(n+m)
vector<int> intersection(vector<int> &a, vector<int> &b)
{

    vector<int> res;
    map<int, bool> seen;
    for (int i = 0; i < a.size(); i++)
    {
        seen[a[i]] = 1;
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (seen[b[i]])
        {
            res.push_back(b[i]);
            seen[b[i]] = 0;
        }
    }
    return res;
}

int main()
{
    FastIO;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> ans = intersection(a, b);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << nl;
    return 0;
}