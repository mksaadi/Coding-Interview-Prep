#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()



void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int draws = n - a - b;
    if ( draws < 0 || ( a == 0 && b > 0 ) || ( b == 0 && a > 0 ) )
    {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;

    n -= draws;
    for ( int i = 1; i <= n; i++ )
    {
        cout << i << " ";
    }
    for ( int i = n + 1; i <= n + draws; i++ )
    {
        cout << i << " ";
    }
    cout << nl;
    for ( int i = 1; i <= n; i++ )
    {
        int x = i + a;
        if ( x > n )
        {
            x -= n;
        }
        cout << x << " ";
    }
    for ( int i = n + 1; i <= n + draws; i++ )
    {
        cout << i << " ";
    }
    cout << nl;
}
int main()
{
    FastIO;
    int t;
    cin >> t;
    while ( t-- )
    {
        solve();
    }
    return 0;
}