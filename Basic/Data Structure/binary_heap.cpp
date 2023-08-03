#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

// binary heap is a binary tree in which the parent node is always smaller or equal
// than the children nodes.

// It supports O(log(n)) for insertion and deletion and O(1) for accessing element.

#define max_size 1000

int n = 0; // size of the heap

int h[max_size];

void insert(int x)
{
    cout << "Insert (" << x << ")\n";
    h[n] = x;
    n++;
    int i = n - 1;
    int par = (i - 1) / 2;
    while (i > 0 and h[i] < h[par])
    {
        swap(h[i], h[par]);
        i = par;
    }
}

int remove_min()
{
    cout << "Remove()\n";
    int ans = h[0];       // min element is at the root
    swap(h[0], h[n - 1]); // now the last element is at the root
    n--;                  // min element removed from the array
    // fix the properties
    int i = 0;
    while (2 * i + 1 < n)
    {
        int j = 2 * i + 1;
        if (j + 1 < n && h[j + 1] < h[j])
        {
            j++;
        }
        if (h[j] >= h[i])
        {
            break;
        }
        swap(h[i], h[j]);
        i = j;
    }
    return h[n];
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << h[i] << " ";
    }
    cout << "\n";
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(x);
        print();
    }
    for (int i = 0; i < n; i++)
    {
        cout << remove_min() << "\n";
        print();
    }

    return 0;
}