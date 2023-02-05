#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using ld = long double;
#define ff first
#define nl "\n"
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define print(v)          \
    for (auto x : v)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << "\n";
const long long INF = 2000000000000000000LL;
const long double EPS = 1e-9;
const long long mod = 1e9 + 7;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define set_precision(x)                              \
    cout.setf(std::ios::fixed, std::ios::floatfield); \
    cout.precision(x);

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
bool visited[11][11];
bool isValid(int i, int j, vector<vector<int>> &matrix)
{
    if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || visited[i][j])
        return false;
    return true;
}


void go(int i, int j, vector<int> &res, vector<vector<int>> &matrix, int direction)
{
    if (!isValid(i, j, matrix))
        return;
    res.push_back(matrix[i][j]);
    visited[i][j] = true;
    if (isValid(i + dx[direction], j + dy[direction], matrix))
    {
        go(i + dx[direction], j + dy[direction], res, matrix, direction);
    }
    else
    {
        direction = (direction + 1) % 4;
        go(i + dx[direction], j + dy[direction], res, matrix, direction);
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int i = 0;
    int j = 0;
    vector<int> res;

    memset(visited, false, sizeof visited);
    go(i, j, res, matrix, 0);
    return res;
}
int main()
{
    FastIO;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    print(spiralOrder(matrix));
    return 0;
}