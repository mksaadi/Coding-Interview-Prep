#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

void miniMaxSum(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    long long min_sum = 0LL;
    long long max_sum = 0LL;
    for (int i = 0; i < 4; i++)
    {
        min_sum += (ll)arr[i];
    }
    for (int i = n - 1; i >= n - 4; i--)
    {
        max_sum += (ll)arr[i];
    }
    cout<<min_sum<<" "<<max_sum<<"\n";
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    miniMaxSum(arr);
    return 0;
}