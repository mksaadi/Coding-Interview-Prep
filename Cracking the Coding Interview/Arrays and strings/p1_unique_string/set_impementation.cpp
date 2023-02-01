#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

bool is_unique(string str)
{
    set<char>st;
    for(int i=0;i<str.size();i++)
    {
        st.insert(str[i]);   
    }
    return st.size()==str.size();

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