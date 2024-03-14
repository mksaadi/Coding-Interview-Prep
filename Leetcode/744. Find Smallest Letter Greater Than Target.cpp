// You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

// Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

char nextGreatestLetter(vector<char> &letters, char target)
{
    int left = -1;              // less/equal than target
    int right = letters.size(); // greater than target
    while (right > left + 1)
    {
        int mid = left + (right - left) / 2;
        if (letters[mid] <= target)
        {
            left = mid;
        }
        else
            right = mid;
    }
    if (right == letters.size())
    {
        return letters[0];
    }
    return letters[right];
}

int main()
{
    FastIO;
    int n;
    char c;
    cin >> n >> c;
    vector<char> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << nextGreatestLetter(v, c) << "\n";

    return 0;
}