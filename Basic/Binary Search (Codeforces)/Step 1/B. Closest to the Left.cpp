#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()

ll n, k;
vector<ll>v(100001);


ll found(ll x)
{
    ll left = -1;
    ll right = n;
    while ( right - left > 1 )
    {
        ll mid = left + ( right - left ) / 2;
        if ( v[mid] <= x )
        {
            left = mid;
        }
        else right = mid;
    }
    return max(0LL, left + 1);
}



int main()
{
    FastIO;
    cin >> n >> k;
    for ( int i = 0; i < n; i++ )
    {
        cin >> v[i];
    }
    for ( int i = 0; i < k; i++ )
    {
        ll x;
        cin >> x;
        cout << found(x) << nl;
    }

    return 0;
}