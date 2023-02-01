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

int n;
int arr[102][102];
int down_right(int i,int j)
{
    if(i<0 || i>=n || j>=n || j<0)return 0;
    return arr[i][j]+down_right(i+1,j+1);
}

int down_left(int i,int j)
{
    if(i<0 || i>=n || j>=n || j<0)return 0;
    return arr[i][j]+down_left(i+1,j-1);
}


int main()
{
 FastIO;
 cin>>n;
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<n;j++)
    {
        cin>>arr[i][j];
    }
 }
 cout<<abs(down_right(0,0) - down_left(0,n-1))<<"\n";

 return 0;
}