#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


/// structure of a linked list

struct ListNode 
{
   int val;
   ListNode* next;
};

/// Node that points to the list's first node
/// initially head is NULL , cz the list is empty


ListNode* Head = NULL;


// insert a node at the top 
void insert_top(int val)
{
    ListNode* a = new ListNode;
    a->val = val;
    a->next= Head;
    Head = a;
}


//

void insert_bottom(int val)
{

    ListNode *new_node = new ListNode;
    new_node->val = val;
    new_node->next = NULL;


    ListNode *a = Head;

    if(Head==NULL)
    {
        Head = new_node;
        return;
    }

    // go to the last node
    while(1)
    {
        if(a->next==NULL)
        {
            a->next = new_node;
            return;
        }
        a = a->next;
    }

}

/// prints the list
void print_list()
{   
    ListNode* a = Head;
    while(a!=NULL)
    {
        cout<<a->val<<" ";
        a = a->next;
    }
    cout<<"\n";
}

void print_recursive(ListNode* a)
{
  cout<<a->val<<" ";
  if(a->next==NULL)
  {
    cout<<"\n";
    return;
  }
  print_recursive(a->next);
}

void print_reverse(ListNode*a)
{
  
  if(a==NULL)
  {
    cout<<"\n";
    return;
  }
  print_reverse(a->next);
  cout<<a->val<<" ";
}

void reverse(ListNode*a)
{
  if(a->next==NULL)
  {
    Head = a;
    return;
  }
  reverse(a->next);
  a->next->next = a;
  a->next = NULL;
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
    //insert_top(x);
    insert_bottom(x);
 }
 //print_list();
 //print_recursive(Head);
 //print_reverse(Head);
 reverse(Head);
 print_list();
 
 return 0;
}