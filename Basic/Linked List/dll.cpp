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



struct Node{
    int val;
    Node* prev;
    Node* next;
};


Node* Head = NULL;  // first node
Node* Tail = NULL;  // last node



void pushFront(int val)
{
    // new node will become the first node
    Node* new_node = new Node;  
    new_node->val = val;
    new_node->prev = NULL;
    if(Head == NULL)
    {
        // new node will also be the last node
        Tail = new_node;
        new_node->next = NULL;
    }
    else 
    {
        // list has other elements
        new_node->next = Head;
    }
    Head = new_node;
}

void pushBack(int val)
{
    Node* new_node = new Node;  
    new_node ->next = NULL;
    new_node->val   = val;
   // new node will become the last element and become the new tail

   if(Tail==NULL)
   {
     // if theere are no elements
     Head = new_node;
     new_node->prev = NULL;
   }
   else
   {
        new_node->prev = Tail;    
        Tail->next = new_node;
   }
   Tail = new_node;
}


void print_list()
{   
    Node* a = Head;
    while(a!=NULL)
    {
        cout<<a->val<<" ";
        a = a->next;
    }
}





int main()
{
 FastIO;
 int t;
 cin>>t;
 
 for(int i=0;i<t;i++)
 {
    int x;
    cin>>x;
    pushBack(x);
    
 }
 print_list();

 
 
 return 0;
}