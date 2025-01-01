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


void Unite(int a, int b, vector<int>& Link, vector<int>& Size, vector<int>& Minimum, vector<int>& Maximum)
{
    a = Find(a, Link);
    b = Find(b, Link);
    if ( a == b )return;
    if ( Size[a] < Size[b] )
    {
        swap(a, b);
    }
    Minimum[a] = min(Minimum[b], Minimum[a]);
    Maximum[a] = max(Maximum[b], Maximum[a]);
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
    vector<int>Minimum(n + 1);
    vector<int>Maximum(n + 1);
    for ( int i = 1; i <= n; i++ )
    {
        Link[i] = i;
        Minimum[i] = i;
        Maximum[i] = i;
    }
    for ( int i = 0; i < m; i++ )
    {
        string com;
        int a, b;
        cin >> com;
        if ( com[0] == 'u' )
        {
            cin >> a >> b; 
            Unite(a, b, Link, Size, Minimum, Maximum);
        }
        else
        {
            cin >> a;
            int ans = Find(a, Link);
            cout << Minimum[ans] << " " << Maximum[ans] << " " << Size[ans] << nl;
        }
    }
    return 0;
}