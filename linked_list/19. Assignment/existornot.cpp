//cheak whether the data is repeating or not;

//*******************************************************************************
#include <bits/stdc++.h>
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

int findlength(node *head)
{
    int length = 0;
    node *curr = head;
    while (curr != NULL)
    {
        length = length + 1;
        curr = curr->next;
    }
    return length;
}
int ispalidrome(node *head, int key)
{
    node *curr = head;
    int times = 0;
    for (int i = 0; i < findlength(head); i++)
    {
        if (curr->data == key)
        {
            times = times + 1;
        }
        curr = curr->next;
    }
    if (times > 1)
    {
        return 1;
    }
    else
        return 0;
}
void print(node *head)
{
    node *curr = head;
    // we are making a curr to travell to linked list;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main()
{
    node *head = takeinput();
    print(head);
    int i;

    cout << "input element and index i at which you check" << endl;
    cin >> i;

    int k = ispalidrome(head, i);
    if (k == 1)
    {
        cout << "true" << endl;
    }
    if (k == 0)
    {
        cout << "false" << endl;
    }

    return 0;
}