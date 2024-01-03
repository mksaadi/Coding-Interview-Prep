#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int numberOfBeams(vector<string> &bank)
{
    int res = 0;
    int multiplier = 0;
    for (int i = 0; i < bank.size(); i++)
    {
        int nsd = count(bank[i].begin(), bank[i].end(), '1');
        if (nsd != 0)
        {
            res += nsd * multiplier;
            multiplier = nsd;
        }
    }
    return res;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<string> bank(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bank[i];
    }
    cout << numberOfBeams(bank) << "\n";

    return 0;
}