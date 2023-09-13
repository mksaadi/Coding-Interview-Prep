#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool wordPattern(string pattern, string s)
{
    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word)
    {
        words.push_back(word);
    }
    if (words.size() != pattern.size())
    {
        return false;
    }
    map<char, string> mp;
    map<string, char> pm;
    int i = 0;
    int j = 0;
    while (i < pattern.size() && j < words.size())
    {
        char c = pattern[i];
        string word = words[j];
        if (mp.find(c) != mp.end() && mp[c] != word)
        {
            return false;
        }
        if (pm.find(word) != pm.end() && pm[word] != c)
        {
            return false;
        }
        mp[c] = word;
        pm[word] = c;
        i++;
        j++;
    }
    return true;
}
int main()
{
    FastIO;
    string pattern, s;
    cin >> pattern;
    cin.ignore();
    getline(cin, s);
    cout << pattern << "\n";
    cout << s << "\n";
    cout << (wordPattern(pattern, s) == 1 ? "True\n" : "False\n");
    return 0;
}