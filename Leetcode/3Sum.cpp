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

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    //print(nums);
    vector<vector<int>> sol;
    set< tuple<int,int,int> > st;
    for(int i=0;i<nums.size();i++)
    {
        int nt  = -nums[i];
        //cout<<"New Target : "<<nt<<"\n";
        int left = i+1;
        int right = nums.size()-1;
        //cout<<"Left : "<<left<<"\n";
        //cout<<"Right :"<<right<<"\n";
        while(left<right && i!=left && i!=right && left!=right)
        {
            //cout<<"Inside while : ";
            if(nums[left] + nums[right] == nt)
            {
                //cout<<"Solution Found \n";
                tuple<int,int,int> t = {nums[i],nums[left],nums[right]};
                st.insert(t);
                left++;
                right--;
            }
            else if(nums[left] + nums[right]>nt)
            {
                right--;
            }
            else 
            {
                left++;
            }
           // cout<<"Left : "<<left<<"\n";
            //cout<<"Right :"<<right<<"\n";

        }
    }

    for(auto x : st)
    {
        vector<int>v;
        tuple<int,int,int>t = x;
        v.push_back(get<0>(t));
        v.push_back(get<1>(t));
        v.push_back(get<2>(t));
        sol.push_back(v);
    }

    return sol;
}

int main()
{
    FastIO;
    int n;
    cin>>n;
    vi nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    //print(nums);
    vector< vector<int> > sol = threeSum(nums);
    for(int i=0;i<sol.size();i++)
    {
        for(int j=0;j<sol[i].size();j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}