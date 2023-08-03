#include <bits/stdc++.h>
using namespace std;

void printBin(int n, int x)
{

    for (int i = n - 1; i >= 0; i--)
    {
        cout << (x & (1 << i) ? '1' : '0');
    }
    cout << "\n";
}

int main()
{
   
    int n;
    cin >> n;
    vector<int> ans;
    int len = 1 << n; // 2^n
    for (int i = 0; i < len; i++)
    {
        ans.push_back((i >> 1) ^ i);
    }
   
    for (int i = 0; i < ans.size(); i++)
    {
        printBin(n, ans[i]);
    }
    return 0;
}