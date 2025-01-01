#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()

int findMin(vector<int>& nums)
{
    int l = 0;           // nums[l] >= num[0]
    int r = nums.size(); // nums[r] < nums[0]
    while ( l + 1 < r )
    {
        int mid = ( l + ( r - l ) / 2 );
        if ( nums[mid] > nums[0] )
            l = mid;
        else
            r = mid;
    }
    return nums[ r  % nums.size()];
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> nums(n);
    for ( int i = 0; i < n; i++ )
        cin >> nums[i];

    cout << findMin(nums) << "\n";
    return 0;
}