#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
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
void pushBack(int val,ListNode* Head)
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


int main()
{
 ListNode* Head = NULL;
 int n;cin>>n;
 for(int i=0;i<n;i++)
 {  
    int val; 
    cin>>val;
    pushBack(val,Head);
 }
 if(hasCycle(Head))
 {
    cout<<"HAS CYCLE\n";
 }
 else 
 {
    cout<<"NO CYCLE FOUND\n";
 }

 return 0;
}