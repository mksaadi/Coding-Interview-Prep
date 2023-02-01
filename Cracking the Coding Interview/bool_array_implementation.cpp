#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

bool is_unique(string str)
{
    vector<bool>seen(256,false);
    for(int i=0;i<str.size();i++)
    {
        if(seen[str[i]])
        {
            return false;
        }
        else 
        {
            seen[str[i]]=1;
        }
    }
    return true;
}


int main()
{
 FastIO;
 int t;
 cin>>t;
 while(t--)
  {
    string str;
    cin>>str;
    if(is_unique(str))
    {
        cout<<"YES\n";
    }
    else 
    {
        cout<<"NO\n";
    }
   
  }
 return 0;
}