#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool canConstruct(string ransomNote, string magazine)
{
    vector<int> cnt1(260, 0);
    for (int i = 0; i < magazine.size(); i++)
    {
        cnt1[magazine[i]]++;
    }
    for (int i = 0; i < ransomNote.size(); i++)
    {
        if (cnt1[ransomNote[i]] == 0)
            return false;
        cnt1[ransomNote[i]]--;
    }
    return true;
}

int main()
{
    FastIO;
    string a, b;
    cin >> a >> b;
    cout << canConstruct(a, b) << "\n";
    return 0;
}