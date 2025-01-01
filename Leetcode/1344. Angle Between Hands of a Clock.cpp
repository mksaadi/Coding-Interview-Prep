//https://leetcode.com/problems/angle-between-hands-of-a-clock/description/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()


double angleClock(int h, int m) {
    h = h % 12;
    double ht = ( 30 * h ) + ( 0.5 * ( double )m );
    double mt = 6 * m;
    double ans = ht - mt;
    ans = abs(fmod(ans, 360));
    if ( ans > 180 )
    {
        ans = 360 - ans;
    }
    return ans;
}
int main()
{
    FastIO;
    int h, m;
    cin >> h >> m;
    cout << angleClock(h, m) << nl;
    return 0;
}