#include <bits/stdc++.h>
//calculate the mid without finding the length of linked list;
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int findmid(node *head)
{
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    int k = slow->data;
    return k;

}
node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = head;
        }
        else
        {
            // node *current = head;
            // while (current->next != NULL)
            // {
            //     current = current->next;
            //             }
            // current->next = newnode;
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
int main()
{
    node *head = takeinput();
    //print(head);
    
    int k = findmid(head);
    cout<<k<<" "<<endl;
    return 0;
}