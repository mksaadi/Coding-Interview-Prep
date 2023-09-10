#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    map<char, bool> seen;
    int l = 0;
    int ans = min(1,n);
    seen[s[0]] = true;
    for (int i = 1; i < n; i++)
    {
        while (seen[s[i]])
        {
            seen[s[l]] = false;
            l++;
        }
        seen[s[i]] = true;
        ans = max(ans, i - l + 1);
    }

    return ans;
}

int main()
{
    FastIO;
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << "\n";

    return 0;
}