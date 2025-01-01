#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()


bool Possible(ll s, ll n, ll w, ll h)
{
    return ( ( s / w ) * ( s / h ) >= n );
}

int main()
{
    FastIO;
    ll w, h, n;
    cin >> w >> h >> n;
    ll left = -1;
    ll right = 1;
    while ( !Possible(right, n, w, h) )
    {
        right *= 2LL;
    }
    while ( right - left > 1 )
    {
        ll mid = ( left + ( right - left ) / 2 );
        if ( Possible(mid, n, w, h) )
        {
            right = mid;
        }
        else left = mid;
    }
    cout << right << nl;
    return 0;
}