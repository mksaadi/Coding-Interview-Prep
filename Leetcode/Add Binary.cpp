#include <bits/stdc++.h>
using namespace std;
string addBinary(string a, string b)
{
    int i = (int)(a.size())-1;
    int j = (int)(b.size())-1;
    string res;
    int carry = 0;
    while(1)
    {
        if(i<0 && j<0 )
        {
            break;;
        }
        int ia = i>=0?a[i]-'0':0; // converting to int;i<0 then string a has ended ; so we assume 0 in that place

        int jb = j>=0?b[j]-'0':0; // j<0 then string b has ended ; so we assume 0 in that place
        int rb = (ia+jb+carry)%2; // value always between 1 and 0;


        res.insert(res.begin(),rb+'0');
        carry = (carry+ia+jb)/2;
        --i;
        --j;

    }
    if(carry==1)res.insert(res.begin(),'1');
    return res;
   
    

}
int main()
{
    string a = "11", b = "1";
    cout<<addBinary(a,b)<<"\n";
    return 0;
}