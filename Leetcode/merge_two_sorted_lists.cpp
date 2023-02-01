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
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define print(v) for(auto x:v){cout<<x<<" ";}cout<<endl; //print the vector
const long long INF = 2000000000000000000LL;      // 2e18
const long double EPS = 1e-9;
const long long mod = 1e9+7;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
//cout.setf( std::ios::fixed, std:: ios::floatfield );               // floatfield not set
//cout.precision(10);

struct ListNode {
    int val;
    ListNode *next;
};


ListNode* list1=NULL;

ListNode* list2=NULL;

ListNode* list3=NULL;





void insert_bottom(int val,ListNode* &starting_address)
{
    ListNode* new_node = new ListNode;
    new_node->next = NULL;
    new_node->val = val;
 
    ListNode *temp = starting_address;

    if(starting_address==NULL)
    {
        starting_address = new_node;
        return;
    }

    while(1)
    {
        if(temp->next==NULL)
        {
            temp->next=new_node;
            return;
        }
        temp = temp->next;
    }
}


void print_list(ListNode* starting_address)
{
    while(starting_address!=NULL)
    {
        cout<<starting_address->val<<" ";
        starting_address = starting_address->next;
    }
    cout<<"\n";
    return;
}


// solve function
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     ListNode * temp1 = list1;
     ListNode * temp2 = list2;
     ListNode * merged = NULL;

        while(1)
        {
            if(temp1 == NULL || temp2 == NULL)
            {
                break;
            }
            if(temp1->val <= temp2->val)
            {
                if(merged==NULL)
                {
                   ListNode * newNode = new ListNode();
                   newNode->val = temp1->val;
                   newNode->next = NULL;
                   merged = newNode;
                  
                }
                else
                {
                      ListNode * newNode = new ListNode();
                      newNode->val = temp1->val;
                      newNode->next = NULL;
                      //push _back the newnode

                      ListNode* t = merged;
                      while(1)
                      {
                         if(t->next == NULL)
                         {
                            t->next = newNode;
                            break;
                         }
                         t = t->next;
                      }
                }
                temp1 = temp1->next;
              
            }
            else 
            {
                if(merged==NULL)
                {
                    ListNode * newNode = new ListNode();
                    newNode->val = temp2->val;
                    newNode->next = NULL;
                    merged = newNode;
                }
                else 
                {
                       ListNode *  newNode = new ListNode();
                       newNode->val = temp2->val;
                       newNode->next = NULL;
                       ListNode* t = merged;
                      while(1)
                      {
                         if(t->next == NULL)
                         {
                            t->next = newNode;
                            break;
                         }
                         t = t->next;
                      }
                }
                temp2 = temp2->next;
              
            }
        }

            while(temp1!= NULL)
            {
                
                if(merged==NULL)
                {
                    ListNode * newNode = new ListNode();
                    newNode->val = temp1->val;
                    newNode->next = NULL;
                    merged = newNode;
                }
                else
                {
                    ListNode * newNode = new ListNode();
                    newNode->val = temp1->val;
                    newNode->next = NULL;
                     ListNode* t = merged;
                      while(1)
                      {
                         if(t->next == NULL)
                         {
                            t->next = newNode;
                            break;
                         }
                         t = t->next;
                      }
                }
                temp1 = temp1->next;
            }
        
        
     
            while(temp2!= NULL)
            {
                 
                if(merged==NULL)
                {
                    ListNode * newNode = new ListNode();
                    newNode->val = temp2->val;
                    newNode->next = NULL;
                    merged = newNode;
                }
                else
                {
                     ListNode * newNode = new ListNode();
                     newNode->val = temp2->val;
                     newNode->next = NULL;
                     ListNode* t = merged;
                      while(1)
                      {
                         if(t->next == NULL)
                         {
                            t->next = newNode;
                            break;
                         }
                         t = t->next;
                      }
                }
                temp2 = temp2->next;
            }

            return merged;
    
}

int main()
{
 FastIO;
 int n,m;
 cin>>n>>m;
 for(int i=0;i<n;i++)
 {
    int x;
    cin>>x;
    insert_bottom(x,list1);
 }
 for(int i=0;i<m;i++)
 {
    int x;
    cin>>x;
    insert_bottom(x,list2);
 }

  ListNode* merged_list = mergeTwoLists(list1,list2);

 // print_list(list1);
 // print_list(list2);
  print_list(merged_list);

 return 0;
}