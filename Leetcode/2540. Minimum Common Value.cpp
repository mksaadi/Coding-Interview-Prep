#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int getCommon(vector<int> &nums1, vector<int> &nums2)
{
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < nums1.size() && idx2 < nums2.size())
    {
        if (nums1[idx1] == nums2[idx2])
        {
            return nums1[idx1];
        }
        if (nums1[idx1] < nums2[idx2])
        {
            idx1++;
        }
        else
            idx2++;
    }
    return -1;
}

int main()
{
    FastIO;
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < m; i++)
        cin >> v2[i];

    cout << getCommon(v1, v2) << nl;
    return 0;
}