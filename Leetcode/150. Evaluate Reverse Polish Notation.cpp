#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

bool isOperation(string str)
{
    int n = str.size();
    if (n > 1)
        return false;
    if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
        return true;
    return false;
}
int evalRPN(vector<string> &tokens)
{
    int n = tokens.size();
    stack<int> st;
    int res;
    for (int i = 0; i < n; i++)
    {
        if (isOperation(tokens[i]))
        {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();

            if (tokens[i][0] == '+')
            {
                res = operand1 + operand2;
                st.push(res);
                continue;
            }
            if (tokens[i][0] == '/')
            {
                res = operand2 / operand1;
                st.push(res);
                continue;
            }
            if (tokens[i][0] == '-')
            {
                res = operand2 - operand1;
                st.push(res);
                continue;
            }
            if (tokens[i][0] == '*')
            {
                res = operand1 * operand2;
                st.push(res);
                continue;
            }
        }
        else
        {
            st.push(atoi(tokens[i].c_str()));
        }
    }
    if (!st.empty())
    {
        res = st.top();
    }
    return res;
}
int main()
{
    FastIO;

    return 0;
}