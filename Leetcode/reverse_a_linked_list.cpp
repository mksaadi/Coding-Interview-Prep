#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct ListNode 
{
    int val;
    ListNode * next;
};

ListNode* pushBack(ListNode* head,int val)
{ 
    ListNode* newNode = new ListNode;
    newNode->val = val;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    ListNode * temp = head;
    while(1)
    {
        if(temp->next==NULL)
        {
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }

}

void printList (ListNode * head)
{
    if(head==NULL)
    {
        cout<<"EMPTY!!\n";
        return;
    }
    ListNode*temp = head;
    while(1)
    {
        if(temp==NULL)
        {
            cout<<"\n";
            return;
        }
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    
}

void reversePrint(ListNode* head)
{
    if(head==NULL)
    {
        return;
    }
    reversePrint(head->next);
    cout<<head->val<<" ";
}

ListNode* reverseList(ListNode*head, ListNode*a)
{
    if(a->next==NULL)
    {
        head = a;
        return head;
    }
    head  =  reverseList(head,a->next);
    a->next->next = a;
    a->next = NULL;
    return head;
}



int main()
{
 FastIO;
 ListNode * head = NULL;
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
    int x;cin>>x;
    head = pushBack(head,x);
 }
 printList(head);
 reversePrint(head);
 cout<<"\n";
 printList(head);
 head = reverseList(head,head);
 printList(head);
 return 0;
}