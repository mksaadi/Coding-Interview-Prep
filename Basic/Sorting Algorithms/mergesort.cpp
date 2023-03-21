#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using ld = long double;
#define ff first
#define nl "\n"
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define print(v)          \
    for (auto x : v)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << "\n";
const long long INF = 2000000000000000000LL;
const long double EPS = 1e-9;
const long long mod = 1e9 + 7;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define set_precision(x)                              \
    cout.setf(std::ios::fixed, std::ios::floatfield); \
    cout.precision(x);


void merge(int l,int mid,int r,vector<int>& v)
{
    vector<int>res;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r)
    {
        if(v[i]<=v[j])
        {
            res.push_back(v[i++]);;
            
        }
        else
        {
            res.push_back(v[j++]);
        }
    }
    while(i<=mid)
    {
        res.push_back(v[i++]);
    }
    while(j<=r)
    {
        res.push_back(v[j++]);
    }
    j = 0;
    for(int i=l;i<=r;i++)
    {
        v[i] = res[j++];
    }
}

void mergesort(int l,int r,vector<int>&v)
{
    if(l>=r)return;
    int mid = l+(r-l)/2;
    mergesort(l,mid,v);
    mergesort(mid+1,r,v);
    merge(l,mid,r,v);
}


int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int>x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << "Before Sorting :  \n";
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n";
    mergesort(0,n-1,x);
    cout << "After Sorting :  \n";
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << nl;
    return 0;
}