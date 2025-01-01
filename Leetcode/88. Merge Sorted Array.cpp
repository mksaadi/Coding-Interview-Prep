#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

void merge(vector<int> &c, int m, vector<int> &b, int n)
{
   
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (j >= 0)
    {
        if (i >= 0 && c[i] > b[j])
        {
            c[k--] = c[i--];
        }
        else
        {
            c[k--] = b[j--];
        }
    }
}
int main()
{
    FastIO;
    int m, n;
    cin >> m >> n;
    vector<int> a(m + n, 0);
    vector<int> b(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    merge(a, m, b, n);
    for (int i = 0; i < m + n; i++)
    {
        cout << a[i] << " ";
    }
    cout << nl;

    return 0;
}