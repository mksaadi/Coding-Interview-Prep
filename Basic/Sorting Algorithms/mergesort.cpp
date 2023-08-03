#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

void Merge(int left, int mid, int right, vector<int> &v)
{
    vector<int> temp;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (v[i] < v[j])
        {
            temp.push_back(v[i++]);
        }
        else
        {
            temp.push_back(v[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(v[i++]);
    }
    while (j <= right)
    {
        temp.push_back(v[j++]);
    }
    int x = 0;
    for (int k = left; k <= right; k++)
    {
        v[k] = temp[x++];
    }
}

void MergeSort(int left, int right, vector<int> &v)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    MergeSort(left, mid, v);
    MergeSort(mid + 1, right, v);
    Merge(left, mid, right, v);
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> v(n);
    cout << "Before Sorting : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cout << v[i] << " ";
    }
    cout << nl;
    MergeSort(0, n - 1, v);
    cout << "After Sorting : \n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << nl;
    return 0;
}