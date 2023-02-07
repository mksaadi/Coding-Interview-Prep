#include <bits/stdc++.h>
using namespace std;


// naive  implementation 


string multiply(string&a,char& b)
{
    string res;
    int n = a.size();
    int carry = 0;
    for(int i=n-1;i>=0;i--)
    {
        int d1 = a[i]-'0';
        int d2 = b-'0';
        int mult = ((d1*d2)+carry)%10;
        carry = ((d1*d2)+carry)/10;
        res.insert(res.begin(),(mult+'0'));
    }
    if(carry>0)res.insert(res.begin(),carry+'0');
    return res;
}

string addString(string& a,string& b)
{
    string res;
    int n = a.size();
    int m = b.size();
    int carry = 0;
    for(int i=n-1,j=m-1;i>=0 || j>=0;i--,j--)
    {
        int d1 = i>=0 ? a[i]-'0' : 0;
        int d2 = j>=0 ? b[j]-'0': 0;
        int mult = ((d1+d2)+carry)%10;
        carry = ((d1+d2)+carry)/10;
        res.insert(res.begin(),(mult+'0'));
    }
    if(carry>0)res.insert(res.begin(),carry+'0');
    return res;
}



string  stringMultiply(string& a, string& b)
{
    int n = a.size();
    int m = b.size();
    vector<string>v;
    for(int i=m-1;i>=0;i--)
    {
        v.push_back(multiply(a,b[i]));
    }
    if(v.size() == 1)
    {
        string res = "";
        for(auto i:v)
        {
            res+=i;
        }
        if(res[0]=='0')
        {
            return "0";
        }
        return res;

    }
    string add = "";
    int max_size = 0;
    for(int i=0;i<v.size();i++)
    {
        v[i]+=add;
        max_size = max(max_size,(int)v[i].size());
        add+='0';
    }
    string res;
    for(int i=0;i<(int)v.size()-1 ;i++)
    {
       res = (addString(v[i],v[i+1]));
       v[i+1] = res;
    }
    if(res[0]=='0')
    {
        return "0";
    }
    return res;
}




int main()
{
 string a = "91";
 string b = "20";
 cout<<stringMultiply(a,b)<<"\n";
 return 0;
}