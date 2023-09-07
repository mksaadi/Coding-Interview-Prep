#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int lengthOfLastWord(string s)
{
    string last_word = "";
    int len = s.size();
    bool found = false;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            last_word += s[i];
            found = true;
        }
        else if (s[i] == ' ' && found)
        {
            return last_word.size();
        }
    }
    return last_word.size();
}

int main()
{
    FastIO;
    string s;
    cin >> s;
    cout << lengthOfLastWord(s) << "\n";
    return 0;
}