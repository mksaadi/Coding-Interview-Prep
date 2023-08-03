#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define nl "\n" 
#define all(x) (x).begin(), (x).end()
vector<int> breakingRecords(vector<int> scores) {
    int max_cnt = 0;
    int min_cnt = 0;
    int max = scores[0];
    int min = scores[0];
    for(int i=0;i<scores.size();i++)
    {
        if(scores[i]>max)
        {
            max_cnt++;
            max = scores[i];
        }
        if(scores[i]<min)
        {
            min_cnt++;
            min = scores[i];
        }
    }
    vector<int>ans = {max_cnt,min_cnt};
    return ans;
}
int main()
{
 FastIO;
 int n;
 cin>>n;
 vector<int>scores(n);
 for(int i=0;i<n;i++)
 {
    cin>>scores[i];
 }
 vector<int>ans = breakingRecords(scores);
 
 cout<<ans[0]<<" "<<ans[1]<<"\n";
 
 
 return 0;
}