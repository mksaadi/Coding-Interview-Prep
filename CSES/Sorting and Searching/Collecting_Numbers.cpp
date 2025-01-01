#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int>v(n), pos(n);
    for ( int i = 0; i < n; i++ )
    {
        cin >> v[i];
        v[i]--;
        pos[v[i]] = i;
    }
    int rounds = 1;
    for ( int i = 1; i < n; i++ )
    {
        if ( pos[i] < pos[i - 1] )rounds++;
    }
    cout << rounds << nl;

    return 0;
}