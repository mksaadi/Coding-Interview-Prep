#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

set<string> permutations;
string res;

void generatePermutation(string str, vector<bool> &chosen)
{
    if (res.size() == str.size())
    {
        permutations.insert(res);
    }
    else
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            res.push_back(str[i]);
            generatePermutation(str, chosen);
            chosen[i] = false;
            res.pop_back();
        }
    }
}

int main()
{
    FastIO;
    string str;
    cin >> str;
    int n = str.size();
    vector<bool> chosen(n, false);
    generatePermutation(str, chosen);
    cout << permutations.size() << nl;
    for (auto i : permutations)
    {
        cout << i << "\n";
    }

    return 0;
}