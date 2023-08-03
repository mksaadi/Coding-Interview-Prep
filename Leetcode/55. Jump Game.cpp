#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

// Greedy solution
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int last_reached = 0;
    int i = 0;
    while (i <= last_reached)
    {
        if (last_reached >= n - 1)
        {
            return true;
        }
        last_reached = max(last_reached, i + nums[i]);
        i++;
    }
    return false;
}

int main()
{
    FastIO;
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    if(canJump(nums))
    {
        cout<<"True\n";
    }
    else cout<<"False\n";
    return 0;
}