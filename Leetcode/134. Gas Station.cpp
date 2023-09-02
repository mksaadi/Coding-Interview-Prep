#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    vector<int> dif(n);
    int dif_sum = 0;
    for (int i = 0; i < n; i++)
    {
        dif[i] = gas[i] - cost[i];
        dif_sum += dif[i];
    }
    if (dif_sum < 0)
    {
        return -1;
    }
    int ans = 0;
    int prof = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        prof += dif[i];
        if (prof < 0)
        {
            prof = 0;
            ans = i + 1;
        }
    }
    return ans;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> gas(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> gas[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    cout << canCompleteCircuit(gas, cost) << "\n";
    return 0;
}