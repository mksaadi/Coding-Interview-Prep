#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned  long long;
using pi=pair<int,int>;
using pl=pair<ll,ll>;
using vi=vector<int>;
using vl=vector<ll>;
using vpi=vector<pi>;
using vpl=vector<pl>;
using ld = long double;
#define ff first
#define nl "\n" 
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<"\n";
const long long INF = 2000000000000000000LL;
const long double EPS = 1e-9;
const long long mod = 1e9+7;
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define set_precision(x) cout.setf(std::ios::fixed, std::ios::floatfield);cout.precision(x);

struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


  bool hasCycle(ListNode *head) {
        if(head==NULL)return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow!=NULL && fast!=NULL)
        {
            if(fast==slow)return true;
            fast = fast->next;
            slow = slow->next;
            if(fast==NULL)return false;
            fast = fast->next;
        }
        return false;
    }
int main()
{
 FastIO;
 int t;
 cin>>t;
 while(t--)
  {
     solve();
  }
 return 0;
}