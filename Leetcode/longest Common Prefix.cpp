#include <bits/stdc++.h>
using namespace std;



bool allMatch(char cur,int j,vector<string>&strs)
{
    for(int i=0;i<strs.size();i++)
    {
        if(j>=strs[i].size() || strs[i][j]!=cur)return false;
    }
    return true;
}

string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for(int i=0;i<strs[0].size();i++)
        {
            char cur = strs[0][i];
            if(!allMatch(cur,i,strs))
            {
                return res;
            }
            else res+=cur;
        }
        return res;
}
int main()
{
 vector<string>strs = {"flower","flow","flight"};
 cout<<longestCommonPrefix(strs)<<"\n";
 return 0;
}