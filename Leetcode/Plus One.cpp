#include <bits/stdc++.h>
using namespace std;

void plusOneHelper(vector<int> &digits,int last,int add)
{
    if(last<0)
    {
        if(add==0)
        {
            return;
        }
        else
        {
            digits.insert(digits.begin(),add);
            return;
        }
    }
    digits[last]+=add;
    if(digits[last]>9)
    {
        int carry = digits[last]/10;
        digits[last]%=10;
        last--;
        plusOneHelper(digits,last,carry);
    }
    else 
    {
        return;
    }
}
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    plusOneHelper(digits,n-1,1);
    return digits;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> digits[i];
    }
    vector<int> result = plusOne(digits);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}