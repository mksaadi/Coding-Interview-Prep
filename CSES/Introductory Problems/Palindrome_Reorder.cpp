#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

string isPossible(string str)
{
    map<char, int> freq;
    bool has_odd_already = false;
    for (auto c : str)
    {
        freq[c]++;
    }
    string first = "";
    string middle = "";
    string last = "";
    for (auto i : freq)
    {
        if (i.second & 1)
        {
            if (has_odd_already)
            {
                return "NO SOLUTION";
            }
            has_odd_already = true;
            for (int j = 0; j < i.second; j++)
            {
                middle += i.first;
            }
        }
        else
        {
            for (int j = 0; j < (i.second / 2); j++)
            {
                first += i.first;
                last += i.first;
            }
        }
    }
    reverse(all(last));
    return (first + middle + last);
}

int main()
{
    FastIO;
    string str;
    cin >> str;
    cout << isPossible(str) << nl;
    return 0;
}