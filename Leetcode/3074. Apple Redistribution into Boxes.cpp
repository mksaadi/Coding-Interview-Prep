#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int minimumBoxes(vector<int> &app, vector<int> &cap)
{
    sort(app.begin(), app.end());
    sort(cap.rbegin(), cap.rend());
    int ans = 0;
    int i = 0;
    int j = 0;
    while (i < app.size() && j < cap.size())
    {
        if (app[i] <= cap[j])
        {
            cap[j] -= app[i];
            i++;
        }
        else
        {
            app[i] -= cap[j];
            j++;
        }
    }
    return j + 1;
}
int main()
{
    FastIO;
    int t = 1;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        minimumBoxes();
    }
    return 0;
}