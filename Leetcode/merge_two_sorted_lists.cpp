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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* pushBack(ListNode* head, int val)
{
    ListNode* newNode = new ListNode;
    newNode->next = NULL;
    newNode->val = val;
    if ( head == NULL )
    {
        head = newNode;
        return head;
    }
    ListNode* temp = head;
    while ( 1 )
    {
        if ( temp->next == NULL )
        {
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
}

void printList(ListNode* head)
{
    if ( head == NULL )
    {
        cout << "EMPTY!!\n";
        return;
    }
    ListNode* temp = head;
    while ( 1 )
    {
        if ( temp == NULL )
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* track = new ListNode;
    ListNode* cur = track;

    while ( list1 && list2 )
    {
        if ( list1->val < list2->val )
        {
            cur->next = list1;
            list1 = list1->next;
        }
        else
        {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    if ( list1 )
    {
        cur->next = list1;
    }
    else
        cur->next = list2;

    return track->next;
}

ListNode* getMiddle(ListNode* head)
{
    ListNode* fast = head->next;
    ListNode* slow = head;
    while ( fast && fast->next )
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* sortList(ListNode* head)
{
    if ( head == NULL || head->next == NULL )
    {
        return head;
    }
    ListNode* left = head;
    ListNode* right = getMiddle(head);
    // split left from right

    ListNode* temp = right->next;
    right->next = NULL;
    right = temp;

    left = sortList(left);
    right = sortList(right);
    return mergeTwoLists(left, right);
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    ListNode* list1 = NULL;

    for ( int i = 0; i < n; i++ )
    {
        int x;
        cin >> x;
        list1 = pushBack(list1, x);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     list2 = pushBack(list2, x);
    // }
    // testing individual helper functions
    // printList(list1);
    // cout << getMiddle(list1) << "\n";
    // printList(list2);
    // cout << getMiddle(list2) << "\n";
    // ListNode *merged = mergeTwoLists(list1, list2);
    // printList(merged);
    // cout << getMiddle(merged) << "\n";
    printList(list1);
    printList(sortList(list1));

    return 0;
}