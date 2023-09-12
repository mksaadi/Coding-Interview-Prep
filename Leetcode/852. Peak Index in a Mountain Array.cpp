#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r + 1) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return l;
}
int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << peakIndexInMountainArray(v);

    return 0;
}