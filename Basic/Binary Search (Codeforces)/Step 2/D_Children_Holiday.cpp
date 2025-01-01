#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

struct asst
{
    ll t, z, y;
};

// maximum ballon possible by assistant i

ll max_possible_for_i(ll T, asst i)
{
    ll zi = i.z;
    ll ti = i.t;
    ll yi = i.y;
    ll batch_time = zi * ti + yi;
    ll batches = T / batch_time;
    ll ballons_made_by_i = batches * zi;
    ll rem_time = T % batch_time;
    if ( rem_time > 0 )
    {
        ballons_made_by_i += min(zi, rem_time / ti);
    }

    return ballons_made_by_i;
}

bool isPossible(ll T, vector<asst>& v, ll m)
{
    if ( T < 0 )
        return false;
    ll total_ballons_made = 0;
    for ( int i = 0; i < v.size(); i++ )
    {
        ll ballons_made_by_i = max_possible_for_i(T, v[i]);
        total_ballons_made += ballons_made_by_i;
    }
    return total_ballons_made >= m;
}
int main()
{
    FastIO;
    ll m, n;
    cin >> m >> n;
    vector<asst> v(n);
    for ( int i = 0; i < n; i++ )
    {
        asst a;
        cin >> a.t;
        cin >> a.z;
        cin >> a.y;
        v[i] = a;
    }

    ll low = -1; // impossible to do in low time
    ll high = 1; // always possible in high time
    while ( !isPossible(high, v, m) )
        high *= 2LL;

    while ( high - low > 1 )
    {
        ll mid = low + ( high - low ) / 2;
        if ( isPossible(mid, v, m) )
        {
            high = mid;
        }
        else
            low = mid;
    }
    cout << high << "\n";
    // time takes to inflate all m ballons is high
    ll inflatedSoFar = 0;
    for ( int i = 0; i < n; i++ )
    {
        if ( inflatedSoFar >= m )
        {
            cout << 0 << " ";
        }
        else
        {
            ll b = max_possible_for_i(high, v[i]);
            if ( inflatedSoFar + b <= m )
            {
                cout << b << " ";
                inflatedSoFar += b;
            }
            else
            {
                cout << m - inflatedSoFar << " ";
                inflatedSoFar = m;
            }
        }
    }
    cout << "\n";

    return 0;
}