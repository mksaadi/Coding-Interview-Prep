#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int minProcessingTime(vector<int> &time, vector<int> &tasks)
{
    sort(time.rbegin(), time.rend());
    sort(tasks.begin(), tasks.end());
    // print(time);
    // print(tasks);
    int ans = INT_MIN;
    int j = 4;
    for (int i = 0; i < time.size(); i++)
    {
        int p_time = time[i] + tasks[j - 1];
        ans = max(ans, p_time);
        j += 4;
    }
    return ans;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> processorTime(n);
    for (int i = 0; i < n; i++)
        cin >> processorTime[i];

    vector<int> tasks(n * 4);
    for (int i = 0; i < n * 4; i++)
    {
        cin >> tasks[i];
    }

    cout << minProcessingTime(processorTime, tasks) << "\n";

    return 0;
}