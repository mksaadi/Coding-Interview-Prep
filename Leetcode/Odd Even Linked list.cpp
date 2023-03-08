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

struct ListNode
{
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

ListNode* oddEvenList(ListNode *head)
{
   if( head == nullptr)return head;
   ListNode *first = head;
   ListNode *second = head->next;
   ListNode *track = second;
   while(second!=nullptr && second->next!=nullptr)
   {
        first->next = second->next;
        first = first->next;
        second->next = first->next;
        second = second->next;
   }
   first->next = track;
   return head;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    ListNode *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        head = pushBack(head, x);
    }
    printList(head);
    ListNode* newhead = oddEvenList(head);
    printList(newhead);

    return 0;
}