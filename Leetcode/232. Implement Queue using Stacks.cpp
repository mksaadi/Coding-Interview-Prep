#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

class MyQueue
{
    stack<int> stack1;
    stack<int> stack2;
    int front;
    public:
    MyQueue() {}

    void push(int x)
    {
        if ( stack1.empty() )
        {
            front = x;
        }
        stack1.push(x);
    }

    int pop()
    {
        if ( stack2.empty() )
        {
            while ( !stack1.empty() )
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int x = stack2.top();
        stack2.pop();
        return x;
    }

    int peek()
    {
        if ( !stack2.empty() )
        {
            return stack2.top();
        }
        return front;
    }

    bool empty() { return ( stack1.empty() && stack2.empty() ); }
};

int main()
{
    FastIO;

    return 0;
}