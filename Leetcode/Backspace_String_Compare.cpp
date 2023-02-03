#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned  long long;
using pi=pair<int,int>;
using pl=pair<ll,ll>;
using vi=vector<int>;
using vl=vector<ll>;
using vpi=vector<pi>;
using vpl=vector<pl>;
using ld = long double;
#define ff first
#define nl "\n" 
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<"\n";
const long long INF = 2000000000000000000LL;
const long double EPS = 1e-9;
const long long mod = 1e9+7;
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define set_precision(x) cout.setf(std::ios::fixed, std::ios::floatfield);cout.precision(x);


bool backspaceCompare(string s, string t) {
       string sa = "";
       string st = ""; 
       stack<int>poss;
       stack<int>post;
       for(int i=0;i<s.size();i++)
       {
           if(s[i]!='#')
           {
               poss.push(i);
           }
           else 
           {
               if(!poss.empty())
               {
                    s[poss.top()] = '#';
                    poss.pop();
               }
              
           }
       }
       for(int i=0;i<t.size();i++)
       {
           if(t[i]!='#')
           {
               post.push(i);
           }
           else 
           {
               if(!post.empty()){
                t[post.top()]='#';
                post.pop();
               }
               
           }
       }
       for(int i=0;i<s.size();i++)
       {
            if(s[i]!='#')sa+=s[i];
       }
       
       for(int i=0;i<t.size();i++)
       {
            if(t[i]!='#')st+=t[i];
       }

       return st==sa;
}
int main()
{
 FastIO;
 string s,t;
 cin>>s>>t;
 if(backspaceCompare(s,t))cout<<"true\n";
 else cout<<"false\n";

 return 0;
}