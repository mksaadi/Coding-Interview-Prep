#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()
const int inf = 1e9;

// 00 , 25, 75, 50
int minimumOperations(string s)
{
    int n = s.size();
    bool five_present = false;
    bool zero_present = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (zero_present && s[i] == '0') return n - i - 2;
        if (zero_present && s[i] == '5') return n - i - 2;
        if (five_present && s[i] == '2') return n - i - 2;
        if (five_present && s[i] == '7') return n - i - 2;
        if (s[i] == '0') zero_present = true;
        if (s[i] == '5') five_present = true;
    }
    return (n - zero_present);
}
// int cost(string s, string a)
// {

//     int n = s.size();
//     char l = a[1];
//     char sl = a[0];

//     int op = 0;

//     if (l == sl)
//     {
//         if (count(s.begin(), s.end(), l) < 2)
//         {
//             return inf;
//         }
//     }
//     else
//     {
//         if (count(s.begin(), s.end(), l) == 0 || count(s.begin(), s.end(), sl) == 0)
//         {
//             return inf;
//         }
//     }
//     int l_idx = -1;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (s[i] == l)
//         {
//             l_idx = i;
//             break;
//         }
//         else
//             op++;
//     }
//     bool ok = false;
//     for (int i = l_idx - 1; i >= 0; i--)
//     {
//         if (s[i] == sl)
//         {
//             ok = true;
//             break;
//         }
//         else
//             op++;
//     }
//     if (!ok)
//         op = inf;

//     return op;
// }

// int minimumOperations(string s)
// {
//     vector<string> subs = {"00", "25", "50", "75"};
//     int n = s.size();
//     if (n == 1)
//     {
//         return 1;
//     }
//     if (n == 2)
//     {
//         for (int i = 0; i < subs.size(); i++)
//         {
//             if (s == subs[i])
//             {
//                 return 0;
//             }
//         }
//         if (s[1] == '0' || s[1] == '0')
//             return 1;

//         return n;
//     }
//     int min_cost = n - (count(s.begin(), s.end(), '0'));

//     for (int i = 0; i < subs.size(); i++)
//     {
//         min_cost = min(min_cost, cost(s, subs[i]));
//     }
//     return min_cost;
// }
int main()
{
    FastIO;
    string num;
    cin >> num;
    cout << minimumOperations(num);
    return 0;
}