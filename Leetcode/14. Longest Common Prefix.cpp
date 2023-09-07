#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    string res = "";
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[n - 1];
    for (int i = 0; i < first.size(); i++)
    {
        if (first[i] != last[i])
        {
            return res;
        }
        res += first[i];
    }
    return res;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << longestCommonPrefix(v) << "\n";
    return 0;
}