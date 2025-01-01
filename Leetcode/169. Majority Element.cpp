#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()



int majorityElement(vector<int>& nums) {
    int res = nums[0];
    int cnt = 0;
    for ( int i = 0; i < nums.size(); i++ )
    {
        if ( nums[i] == res )
        {
            cnt++;
        }
        else
        {
            cnt--;
            if ( cnt == 0 )
            {
                res = nums[i];
                cnt = 1;
            }
        }
    }
    return res;
}


int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int>nums(n);
    for ( int i = 0; i < n; i++ )
    {
        cin >> nums[i];
    }
    cout << majorityElement(nums) << nl;

    return 0;
}