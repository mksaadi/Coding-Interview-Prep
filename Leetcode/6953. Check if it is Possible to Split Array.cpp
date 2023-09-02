#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool canSplitArray(vector<int> &nums, int m)
{
    int n = nums.size();
    if (n <= 2)
    {
        return true;
    }

    vector<int> q_sum_left(n);
    vector<int> q_sum_right(n);
    q_sum_left[0] = nums[0];
    q_sum_right[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++)
    {
        q_sum_left[i] = q_sum_left[i - 1] + nums[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        q_sum_left[i] = q_sum_left[i + 1] + nums[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    // cout << "Sum = " << sum << "\n";
    int parts = 0;
    int first = 0;
    int last = n - 1;
    while (first + 1 < last)
    {
        // cout << "Before : \n";
        // cout << "First = " << first << "     value = " << nums[first] << "\n";
        // cout << "Last = " << last << "      value = " << nums[last] << "\n";

        if (nums[first] == nums[last])
        {
            if (first + 1 < n && last - 1 > 0 && q_sum_left[first + 1] < q_sum_right[last - 1])
            {
                // cout << "Con 1\n";
                sum -= nums[last--];
            }
            else if (first + 1 < n && last - 1 > 0 && q_sum_left[first + 1] > q_sum_right[last - 1])
            {
                // cout << "Con 2\n";
                sum -= nums[first++];
            }
            else
            {
                // cout << "Con 3\n";
                sum -= nums[first++];
            }
        }
        else if (nums[first] < nums[last])
        {
            sum -= nums[first++];
        }
        else
        {
            sum -= nums[last--];
        }
        if (sum >= m)
        {
            parts++;
            if (parts >= n - 2)
            {
                return true;
            }
        }
        // cout << "After : \n";
        // cout << "First = " << first << "     value = " << nums[first] << "\n";
        // cout << "Last = " << last << "      value = " << nums[last] << "\n";
        // cout << "Sum = " << sum << "\n";
    }
    return false;
}
int main()
{
    FastIO;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << (canSplitArray(v, m) ? "True\n" : "False") << "\n";
    return 0;
}