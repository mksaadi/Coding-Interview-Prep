#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int ans = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    for (int i = 0, j = 0; i < s.size(); i++)
    {
        if (s[i] >= g[j])
        {
            ans++;
            j++;
            if (j >= g.size())
                break;
        }
    }
    return ans;
}

int main()
{
    FastIO;
    int num_child, num_cookie;
    cin >> num_child >> num_cookie;
    vector<int> g(num_child);
    vector<int> s(num_cookie);
    for (int i = 0; i < num_child; i++)
        cin >> g[i];
    for (int i = 0; i < num_cookie; i++)
        cin >> s[i];
    findContentChildren(g, s);
    return 0;
}