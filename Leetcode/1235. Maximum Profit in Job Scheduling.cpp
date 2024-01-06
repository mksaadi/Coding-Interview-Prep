#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

struct job
{
    int start_time;
    int end_time;
    int profit;
};

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<job> v;
    for (int i = 0; i < startTime.size(); i++)
    {
        job j;
        j.start_time = startTime[i];
        j.end_time = endTime[i];
        j.profit = profit[i];
        v.push_back(j);
    }
    int res = 0;
    sort(v.begin(), v.end(),[](job &a , job &b){
        return a.start_time<b.start_time;
    });
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].start_time << " : " << v[i].end_time << " -> " << v[i].profit << "\n";
    // }

    vector<int>dp(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        dp[i] = dp[i+1];
        int l = i;
        int h = n;
        while(l<h-1)
        {
            int m = l+(h-l)/2;
            if(v[m].start_time >= v[i].end_time)
            {
                h = m;
            }
            else l = m;
        }
        dp[i] = max(dp[i],v[i].profit+dp[h]);
    }

    return dp[0];
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> startTime(n);
    vector<int> endTime(n);
    vector<int> profit(n);
    for (int i = 0; i < n; i++)
    {
        cin >> startTime[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> endTime[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    int ans = jobScheduling(startTime, endTime, profit);
    cout<<ans<<"\n";

    return 0;
}