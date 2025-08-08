#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()


//https://leetcode.com/problems/valid-mountain-array/

bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    n--;
    int i = 0;
    while ( i < n && arr[i] < arr[i + 1] ) {
        i++;
    }
    if ( i == 0 || i == n ) {
        return false;
    }
    while ( i < n && arr[i] > arr[i + 1] ) {
        i++;
    }
    if ( i < n - 1 ) {
        return false;
    }
    return ( i == n );
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> v(n);
    for ( int i = 0; i < n; i++ )
    {
        cin >> v[i];
    }

    if ( validMountainArray(v) )
    {
        cout << "YES" << nl;
    }
    else
    {
        cout << "NO" << nl;
    }

    return 0;
}