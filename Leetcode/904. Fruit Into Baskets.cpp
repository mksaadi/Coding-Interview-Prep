#include <bits/stdc++.h>
using namespace std;


int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    map<int,int>cnt;
    int ans = 0;
    int l = 0;
    int total = 0;
    for(int i=0;i<n;i++)
    {
        cnt[fruits[i]]++;
       
        total++;
        while(cnt.size()>2 && l<n)
        {
            int cur_f = fruits[l];
            cnt[cur_f]--;
            --total;
            l++;
            if(cnt[cur_f]==0){
               
                cnt.erase(cur_f);
               
            }
        }
        ans = max(ans,total);
    }
   

    return ans;

}
int main()
{
    vector<int>fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout<<totalFruit(fruits)<<"\n";
    return 0;
}