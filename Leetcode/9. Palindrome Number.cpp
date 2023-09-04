#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool isPalindrome(int x)
{
    string str = to_string(x);
    int l = 0;
    int r = str.size();
    --r;
    while (l <= r)
    {
        if (str[l++] != str[r--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FastIO;
    int x;
    cin >> x;
    cout << isPalindrome(x) << "\n";

    return 0;
}