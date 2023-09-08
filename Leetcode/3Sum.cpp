#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> sol;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i - 1 > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = (nums.size() - 1);
        while (j < k)
        {
            if (nums[i] + nums[j] + nums[k] == 0)
            {
                sol.push_back({nums[i], nums[j], nums[k]});
                j++;
                while(nums[j] == nums[j-1] && j<k)j++;
            }
            else if (nums[i] + nums[j] + nums[k] > 0)
            {
                k--;
            }
            else
                j++;
        }
    }
    return sol;
}

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    // print(nums);
    vector<vector<int>> sol = threeSum(nums);
    for (int i = 0; i < sol.size(); i++)
    {
        for (int j = 0; j < sol[i].size(); j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}