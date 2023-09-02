#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<pair<int, bool>> events;
    for (int i = 1; i <= n; i++)
    {
        int at, lt;
        cin >> at >> lt;
        events.emplace_back(at, true);
        events.emplace_back(lt, false);
    }
    sort(all(events));
    int max_customers = 0;
    int customers = 0;
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].second)
        {
            customers++;
            max_customers = max(max_customers, customers);
        }
        else
        {
            customers--;
        }
    }
    cout << max_customers << "\n";
    return 0;
}