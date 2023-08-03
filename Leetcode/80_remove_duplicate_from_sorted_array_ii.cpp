#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end

int removeDuplicates(vector<int> &A)
{
    int n = A.size();
    if (n == 0)
        return 0;
    int occur = 1;
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[index] == A[i])
        {
            if (occur == 2)
            {
                continue;
            }
            occur++;
        }
        else
        {
            occur = 1;
        }
        A[++index] = A[i];
    }
    return index + 1;
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