#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()

ll n, k;
vector<ll>v(100001);


// find the last index which contains less than l

ll found_left(ll x)
{
    ll left = -1;
    ll right = n;
    while ( right - left > 1 )
    {
        ll mid = left + ( right - left ) / 2;
        if ( v[mid] < x )
        {
            left = mid;
        }
        else right = mid;
    }
    return left + 1;
}

// find the first index which contains greater than r
ll found_right(ll x)
{
    ll left = -1;
    ll right = n;
    while ( right - left > 1 )
    {
        ll mid = left + ( right - left ) / 2;
        if ( v[mid] > x )
        {
            right = mid;
        }
        else left = mid;
    }
    return right - 1;
}

int main()
{
    FastIO;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        cin >> v[i];
    }
    sort(v.begin(), v.begin() + n);
    // for ( int i = 0; i < n; i++ )
    // {
    //     cout << v[i] << " ";
    // }
    // cout << nl;
    cin >> k;
    for ( int i = 0; i < k; i++ )
    {
        ll l, r;
        cin >> l >> r;
        // cout << "L = " << l << " :  R  = " << r << nl;
        // cout << "Last index which contains an element less than " << l << " = " << found_left(l) << nl;
        // cout << "First index which contains an element greater than " << r << " = " << found_right(r) << nl;
        cout<<found_right(r)-found_left(l)+1<<" ";

    }
    cout << nl;

    return 0;
}