#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

void print(vector<string> res)
{
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
}

void camelCase(string str)
{
    // cout<<str<<"\n";
    vector<string> words;
    string res = "";
    if (str[0] == 'S')
    {
        // split
        if (str[2] == 'M')
        {
            // method
            for (int i = 4; i < str.size() - 2; i++)
            {
                if (isupper(str[i]))
                {
                    words.push_back(res);
                    res = "";
                }
                res += tolower(str[i]);
            }
            words.push_back(res);
        }
        else if (str[2] == 'C')
        {
            // class
            for (int i = 4; i < str.size(); i++)
            {
                if (isupper(str[i]) && i > 4)
                {
                    words.push_back(res);
                    res = "";
                }
                res += tolower(str[i]);
            }
            words.push_back(res);
        }
        else
        {
            for (int i = 4; i < str.size(); i++)
            {
                if (isupper(str[i]) && i > 4)
                {
                    words.push_back(res);
                    res = "";
                }
                res += tolower(str[i]);
            }
            words.push_back(res);
        }
        print(words);
    }
    else
    {
        // combine
        if (str[2] == 'M')
        {
            // method
            for (int i = 4; i < str.size(); i++)
            {
                if (str[i] == ' ')
                    continue;
                if (i > 4 && str[i - 1] == ' ')
                {
                    res += toupper(str[i]);
                }
                else
                    res += str[i];
            }
            res += "()";
        }
        else if (str[2] == 'C')
        {
            for (int i = 4; i < str.size(); i++)
            {
                if (str[i] == ' ')
                    continue;
                if (i == 4 || str[i - 1] == ' ')
                {
                    res += toupper(str[i]);
                }
                else
                    res += str[i];
            }
        }
        else
        {
            // variable
            for (int i = 4; i < str.size(); i++)
            {
                if (str[i] == ' ')
                    continue;
                if (i > 4 && str[i - 1] == ' ')
                {
                    res += toupper(str[i]);
                }
                else
                    res += str[i];
            }
        }
        cout << res << "\n";
    }
}

int main()
{
    FastIO;
    string str;

    while (getline(cin, str))
    {
        str.erase(remove(str.begin(), str.end(), '\r'), str.end());
        camelCase(str);
    }
    return 0;
}