#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

string trimString(string s)
{
    string res = "";
    while (s.back() == ' ')
    {
        s.pop_back();
    }
    while (s.front() == ' ')
    {
        s = s.substr(1);
    }
    for (int i = 0; i < s.size();)
    {
        if (s[i] == ' ')
        {
            res += s[i];
            while (s[i] == ' ')
            {
                i++;
            }
        }
        else
            res += s[i++];
    }
    return res;
}

string reverseWords(string s)
{
    s = trimString(s);
    reverse(s.begin(), s.end());
    bool word_end = false;
    int last_word_pos = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ' && word_end)
        {
            reverse(s.begin() + last_word_pos, s.begin() + i);
            word_end = false;
        }
        if (s[i] != ' ' && !word_end)
        {
            word_end = true;
            last_word_pos = i;
        }
    }
    reverse(s.begin() + last_word_pos, s.end());
    return s;
}
int main()
{
    FastIO;
    string s;
    getline(cin, s);
    cout << reverseWords(s) << "\n";
    return 0;
}