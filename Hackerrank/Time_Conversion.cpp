#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()


string timeConversion(string s)
{
    string res = "";
    string hr = "";
    hr+=s[0];
    hr+=s[1];
    int hour = (hr[0]-'0')*10 + (hr[1]-'0');
    hr = "";
    //cout<<"Hour : "<<hour<<"\n";
    int n = s.size();
    if(s[n-2]=='A')
    {
        hour %=12;
       // cout<<"Hour : "<<hour<<"\n";
        if(hour<10)
        {
            hr = '0'+ to_string(hour);
        }
        else 
        {
            hr = to_string(hour);
        }
    }
    else
    {
        if(hour<12)
        {
            hour+=12;
        }
       // cout<<"Hour : "<<hour<<"\n";
        if(hour<10)
        {
            hr = '0'+ to_string(hour);
        }
        else 
        {
            hr = to_string(hour);
        }

    }
    //cout<<"HR = "<<hr<<"\n";
    res+=hr[0];
    res+=hr[1];
    for(int i=2;i<n-2;i++)
    {
        res+=s[i];
    }
    return res;

    
}
int main()
{
    FastIO;
    string s;
    cin>>s;
    cout<< timeConversion(s)<<"\n";
    return 0;
}