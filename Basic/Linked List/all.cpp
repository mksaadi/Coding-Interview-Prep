/////Implemetation of :
//Insert at the top//
//Insert at the end//
//Insert after a given node//
//Insert before a given node//
//Insert at any given position//
//Delete a Node which holds a given data//////


#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* link;
};

Node * Head = NULL;		




void Insert_Bottom(int x)
{
    Node * temp = new Node;    
    temp->data = x;
   

    temp->link = NULL;			

    if (Head == NULL)    
    {
        Head=temp;
        return;
    }
   

    Node *temp2 = Head;

    while (temp2->link!=NULL)
    {
        temp2 = temp2->link;
    }
    
    temp2->link = temp;


}




void Print_List()
{
    int count = 0;
    Node * temp = Head;
    cout << "List is now : ";
    while (temp!=NULL)
    {
        cout << temp->data<<" ";
        temp = temp->link;
        count++;
    }
    if (count > 1)
    {
        cout << "\n" << "There are " << count << " elements in the list.\n";
    }
    else
    {
        cout << "\n" << "There is " << count << " element in the list.\n";
    }

}

void Insert_Top(int x)
{
  
    Node * temp = new Node;
    temp->data = x;
    temp->link = Head;
    Head = temp;
}




void Insert_After(int number, int insert_value)
{
    int found = 0;
    Node *temp = Head;
    while (temp != NULL)
    {
        if (temp->data == number)
        {
            Node * temp2 = new Node;
            temp2->data = insert_value;
            temp2->link = temp->link;
            temp->link = temp2;
            found = 1;
            break;
        }
        else
        {
            temp = temp->link;
        }

    }
    if (found == 0)
    {
        cout << "The reference number wasn't found in the list.\n";
    }

}


void Insert_Before(int ref, int value)
{

    int found = 0;
    Node * current = Head;
    Node * previous = Head;
    while (current != NULL)
    {

        if (Head->data == ref)
        {
            found = 1;
            Insert_Top(value);
            break;
        }
        else if (current->data == ref)
        {
            found = 1;
            Node * temp = new Node;
            temp->data = value;
            previous->link = temp;
            temp->link = current;
            break;
        }
        else
        {
            previous = current;
            current = current->link;
        }
    }
    if (found == 0)
    {
        cout << "The value you entered wasn't found in the list.\n";
    }



}





void Delete_by_Number(int num)
{
    Node * current = Head;
    Node * previous = Head;
    int found = 0;
    if (Head->data == num)
    {
        Head = Head->link;
    }
    while (current != NULL)
    {

        if (current->data == num)
        {
            found = 1;
            previous->link = current->link;
            break;
        }
        else
        {
            previous = current;
            current = current->link;
        }
    }
    if (found == 0)
        cout << "Number is not in the list.\n";

}


int count_Node(Node * temp)
{
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->link;
    }
    return cnt;
}


void Insert_at_any_Position(int pos, int value)
{
    int count = count_Node(Head);
    if (pos <= count + 1 && pos >= 1)
    {
        if (pos == 1)
        {
            Insert_Top(value);
            return;
        }
        else
        {
            Node * temp = Head;
            Node * temp2 = new Node;
            temp2->data = value;
            for (int i = 0; i < pos - 2; i++)
            {
                temp = temp->link;
            }
            temp2->link = temp->link;
            temp->link = temp2;
        }
    }
    else
    {
        cout << "Invalid position.\n";
    }


}





int main()
{
    int menu, pos, value, x,ref,num;
    cout << "Chose your option :\n";
    cout << "Press 1 to Insert  a vulue at the end of the list.\n";
    cout << "Press 2 to Insert  a vulue at the top of the list.\n";
    cout << "Press 3 to Insert  a vulue after a specific number of the list.\n";
    cout << "Press 4 to Insert  a vulue before a specific number of the list.\n";
    cout << "Press 5 to Insert  a vulue at a specific position of the list.\n";
    cout << "Press 6 to Delete  a vulue from the list.\n";
    cout << "Press 0 to Exit the program.\n";
    while(1)
    {

        cin >> menu;
        if (menu == 1)
        {
            cout << "Enter a number : \n";
            cin >> x;
            Insert_Bottom(x);
            Print_List();
        }
        else if (menu == 2)
        {
            cout << "Enter a number : \n";
            cin >> x;
            Insert_Top(x);
            Print_List();
        }
        else if (menu == 3)
        {
            cout << "Enter the reference  number : \n";
            cin >> value;
            cout << "Enter a number to add after reference number: \n";
            cin >> x;
            Insert_After(value,x);
            Print_List();
        }
        else if (menu == 4)
        {
            cout << "Enter the reference  number : \n";
            cin >> ref;
            cout << "Enter a number to add before the reference number: \n";
            cin >> value;
            Insert_Before(ref, value);
            Print_List();
        }
        else if (menu == 5)
        {
            cout << "Enter the position number : \n";
            cin >>pos;
            cout << "Enter a number to add at that position: \n";
            cin >> value;
            Insert_at_any_Position(pos,value);
            Print_List();
        }
        else if (menu == 6)
        {
            cout << "Enter the number to delete : \n";
            cin >> num;
            Delete_by_Number(num);
            Print_List();

        }
        else if (menu == 0)
        {
            cout << "Bye Bye...!\n";
            break;
        }
    }
    return 0;
}
