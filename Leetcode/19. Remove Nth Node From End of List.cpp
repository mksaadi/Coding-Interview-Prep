#include <bits/stdc++.h>
using namespace std;

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

 struct ListNode {
     int val; 
     ListNode *next;
    
 };
 

ListNode *pushBack(ListNode *head, int val)
{
    ListNode *newNode = new ListNode;
    newNode->next = NULL;
    newNode->val = val;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    ListNode *temp = head;
    while (1)
    {
        if (temp->next == NULL)
        {
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
}

void printList(ListNode *head)
{
    if (head == NULL)
    {
        cout << "EMPTY!!\n";
        return;
    }
    ListNode *temp = head;
    while (1)
    {
        if (temp == NULL)
        {
            cout << "\n";
            return;
        }
        else
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
}


ListNode *removeNthFromEnd(ListNode *head, int n)
{
  ListNode* slow = head;
  ListNode* fast = head;
  for(int i=0;i<=n;i++)
  {
    if(fast == NULL)
    {
        return head->next;
    }
    fast = fast->next;
  }

  while(fast!=NULL)
  {
        fast = fast->next;
        slow = slow->next;
  }
  slow->next = slow->next->next;
  return head;
}

int main()
{
    FastIO;
    ListNode *head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        head = pushBack(head, x);
    }
   
    int dn;
    cin>>dn;
    printList(head);
    head = removeNthFromEnd(head,dn);
    printList(head);

    return 0;
}