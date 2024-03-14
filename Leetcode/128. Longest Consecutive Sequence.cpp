// https://leetcode.com/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int longestConsecutive(vector<int> &a)
{

    unordered_set<int> seen(a.begin(), a.end());
    int max_len = 0;
    for (auto i : seen)
    {
        if (seen.find(i - 1) != seen.end())
        {
            continue;
        }
        int len = 1;
        int cur = i;
        while (seen.find(++cur) != seen.end())
        {
            len++;
        }
        max_len = max(max_len, len);
    }
    return max_len;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << longestConsecutive(v) << "\n";

    return 0;
}