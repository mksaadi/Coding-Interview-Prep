#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()


int Find(int x, vector<int>& Link)
{
    if ( x == Link[x] )return x;
    return Link[x] = Find(Link[x], Link);
}


void Unite(int a, int b, vector<int>& Link, vector<int>& Size)
{
    a = Find(a, Link);
    b = Find(b, Link);
    if ( Size[a] < Size[b] )
    {
        swap(a, b);
    }
    Size[a] += Size[b];
    Link[b] = a;
}

int main()
{
    FastIO;
    int n, m;
    cin >> n >> m;
    vector<int>Link(n + 1);
    vector<int>Size(n + 1, 1);
    for ( int i = 1; i <= n; i++ )
    {
        Link[i] = i;
    }
    for ( int i = 0; i < m; i++ )
    {
        string com;
        int a, b;
        cin >> com >> a >> b;
        if ( com[0] == 'u' )
        {
            Unite(a, b, Link, Size);
        }
        else
        {
            if ( Find(a, Link) == Find(b, Link) )
            {
                cout << "YES" << nl;
            }
            else cout << "NO" << nl;
        }
    }
    return 0;
}