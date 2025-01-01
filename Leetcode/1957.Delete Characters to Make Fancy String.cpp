#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()


string makeFancyString(string s) {
    int n = s.size();
    string res = "";
    res += s[0];
    int cur_cnt = 1;
    for ( int i = 1; i < n; i++ )
    {
        if ( s[i] == s[i - 1] )
        {
            cur_cnt++;
            if ( cur_cnt == 3 ) {
                cur_cnt--;
            }
            else
            {
                res += s[i];
            }
        }
        else
        {
            cur_cnt = 1;
            res += s[i];
        }

    }
    return res;
}



int main()
{
    FastIO;
    string str;
    cin >> str;
    cout << makeFancyString(str) << nl;
    return 0;
}