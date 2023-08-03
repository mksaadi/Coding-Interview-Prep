#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

void insertionSort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int j = i;
        while (j > 0 && v[j] < v[j - 1])
        {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cout << v[i] << " ";
    }
    cout << nl;
    insertionSort(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << nl;
    return 0;
}