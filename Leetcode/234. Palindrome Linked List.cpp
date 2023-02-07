#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


struct ListNode 
{
    int val;
    ListNode* next;
};


ListNode* pushBack(ListNode* head,int val)  
{
    ListNode* newNode = new ListNode;
    newNode->next = NULL;
    newNode->val = val;
    if(head==NULL)
    {
        head = newNode;
        return head;
    }
    ListNode * temp  = head;
    while(1)
    {
        if(temp->next == NULL)
        {
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    
}

void printList(ListNode* head)
{
    if(head==NULL)
    {
        cout<<"EMPTY!!\n";
        return;
    }
    ListNode * temp = head;
    while(1)
    {
        if(temp==NULL)
        {
            cout<<"\n";
            return;
        }
        else 
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
}

//o(n) time and space complexity
// bool isPalindrome(ListNode* head) {
//         string a = "";
//         if(head==NULL)
//         {
//             return true;
//         }
//         ListNode * temp  = head;
//         while(temp!=NULL)
//         {
//             a.push_back(temp->val+'0');
//             temp = temp->next;
//         }
//         int i = 0;
//         int j = (int)a.size() -1;
//         while(i<=j)
//         {
//             if(a[i]!=a[j])
//             {
//                 return false;
//             }
//             j--;
//             i++;
//         }
//         return true;    
// }


bool isPalindrome(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* prev = NULL;
    while(slow!=NULL)
    {
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    ListNode* left = head;
    ListNode* right = prev;

    while(right!=NULL)
    {
        if(left->val != right->val)
        {
            return false;
        }
        right = right->next;
        left = left->next;
    }
    return true;

}

int main()
{
 FastIO;
 ListNode*head = NULL;
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
    int x;cin>>x;
    head = pushBack(head,x);
 }
 printList(head);
 cout<<(isPalindrome(head)?"True\n":"False\n");

 return 0;
}