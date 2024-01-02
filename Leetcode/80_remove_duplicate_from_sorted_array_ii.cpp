#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end
int removeDuplicates(vector<int> &nums)
{
    int k = 1;
    int freq = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            if (freq == 2)
            {
                continue;
            }
            else
            {
                freq = 2;
                nums[k++] = nums[i];
            }
        }
        else
        {
            freq = 1;
            nums[k++] = nums[i];
        }
    }

    return k;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << removeDuplicates(a) << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}