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
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<endl; //print the vector
const long long INF = 2000000000000000000LL;      // 2e18
const long double EPS = 1e-9;
const long long mod = 1e9+7;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
//cout.setf( std::ios::fixed, std:: ios::floatfield );               // floatfield not set
//cout.precision(10);

void print_map(map<char,char>mp)
{
    for (auto x : mp) {
        cout << x.first << " " << x.second << "\n";
    }
}


bool isIsomorphic(string s, string t) {
    map<char,char>mapped_to;
    map<char,char>used_for;
    map<char,bool>seen;
    bool ok = true;
    for(int i=0;i<s.size();i++)
    {
        if(!seen[t[i]])
        {
            seen[t[i]] = true;
            if(used_for.count(s[i])==0 || used_for[s[i]]==t[i])
            {
                mapped_to[t[i]] = s[i];
                used_for[s[i]]=t[i];
            }
            else 
            {
                return false;
            }
            
        }
        else 
        {
            // t[i] is  already mapped  to mapped_to[t[i]]
            if(mapped_to[t[i]]!=s[i])
            {
                return false;
            }
        }

    }
     
    return true;
}

int main()
{
 FastIO;
 string s,t;
 cin>>s>>t;
 if(isIsomorphic(s,t))
 {
    cout<<"true\n";
 }
 else 
 {
    cout<<"false\n";
 }
 
 return 0;
}