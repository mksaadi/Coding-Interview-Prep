#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    if (n > m)
        return findMedianSortedArrays(nums2, nums1);

    int low = 0;
    int right = n;
    int realmidinmergedarray = (n + m + 1) / 2;

    while (low <= right)
    {
        int mid = (low + right) / 2;
        int a_left_size = mid;
        int b_left_size = realmidinmergedarray - mid;

        int a_left = (a_left_size > 0) ? nums1[a_left_size - 1] : INT_MIN;
        int b_left = (b_left_size > 0) ? nums2[b_left_size - 1] : INT_MIN;
        int a_right = (a_left_size < n) ? nums1[a_left_size] : INT_MAX;
        int b_right = (b_left_size < m) ? nums2[b_left_size] : INT_MAX;

        if (a_left <= b_right and b_left <= a_right)
        {
            if ((m + n) % 2 == 0)
                return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
            return max(a_left, b_left);
        }
        else if (a_left > b_right)
        {
            right = mid - 1;
        }
        else
            low = mid + 1;
    }
    return 0.0;
}

int main()
{
    FastIO;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    sort(all(a));
    sort(all(b));
    cout << findMedianSortedArrays(a, b) << "\n";
    return 0;
}