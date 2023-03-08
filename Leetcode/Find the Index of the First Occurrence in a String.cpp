#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0;i+m<=n;i++)
        {
            if(haystack[i]==needle[0])
            {
                string sub = haystack.substr(i,m);
                if(sub == needle)
                {
                    return i;
                }
            }
        }
        return -1;
    }
int main()
{
    ios_base::sync_with_stdio(false);
    string haystack,needle;
    cin>>haystack>>needle;
    cout<<strStr(haystack,needle)<<"\n";
    return 0;
}