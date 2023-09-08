#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

string intToRoman(int num)
{
    vector<pair<string, int>> symbols = {
        {"M", 1000},
        {"CM", 900},
        {"D", 500},
        {"CD", 400},
        {"C", 100},
        {"XC", 90},
        {"L", 50},
        {"XL", 40},
        {"X", 10},
        {"IX", 9},
        {"V", 5},
        {"IV", 4},
        {"I", 1}};
    string ans = "";
    for (int i = 0; i < symbols.size(); i++)
    {
        if (num < 0)
        {
            break;
        }
        int occ = num / symbols[i].second;
        for(int j = 0;j<occ;j++)
        {
            ans+=symbols[i].first;
        }
        num %= symbols[i].second;
    }
    return ans;
}

int main()
{
    FastIO;
    return 0;
}