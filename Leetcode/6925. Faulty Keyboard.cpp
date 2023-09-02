#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

string finalString(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == 'i')
        {
            reverse(res.begin(), res.end());
        }
        else
        {
            res += s[i];
        }
    }
    return res;
}
int main()
{
    FastIO;
    string s;
    cin>>s;
    cout<<finalString(s)<<"\n";
    return 0;
}