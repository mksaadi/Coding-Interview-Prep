#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int romanToInt(string s)
{
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        num += mp[s[i]];
        if (i > 0)
        {
            if ((s[i] == 'V' || s[i] == 'X') && s[i - 1] == 'I')
            {
                num -= (2 * mp['I']);
            }
            if ((s[i] == 'L' || s[i] == 'C') && s[i - 1] == 'X')
            {
                num -= (2 * mp['X']);
            }
            if ((s[i] == 'D' || s[i] == 'M') && s[i - 1] == 'C')
            {
                num -= (2 * mp['C']);
            }
        }
    }
    return num;
}
int main()
{
    FastIO;
    string s;
    cin >> s;
    cout << romanToInt(s) << "\n";
    return 0;
}