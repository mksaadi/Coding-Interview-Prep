#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()

ll n, k;
vector<ll>v(100001);

bool found(ll q)
{
    ll left = 0;
    ll right = n - 1;
    while ( left <= right )
    {
        ll mid = ( left + ( right - left ) / 2 );
        if ( v[mid] == q )
        {
            return true;
        }
        else if ( v[mid] < q )
        {
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return false;
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
        if ( found(x) )
        {
            cout << "YES" << nl;
        }
        else cout << "NO" << nl;
    }
    return 0;
}