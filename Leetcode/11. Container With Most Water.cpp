#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

int maxArea(vector<int> &heights)
{
    int n = heights.size();
    int left = 0;
    int right = n - 1;
    int max_area = 0;
    while (left < right)
    {
        int area = min(heights[left], heights[right]) * (right - left);
        max_area = max(max_area, area);
        if (heights[left] < heights[right])
            left++;
        else if (heights[left] > heights[right])
            right--;
        else
        {
            left++;
            right--;
        }
    }
    return max_area;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    cout << maxArea(heights) << "\n";
    return 0;
}