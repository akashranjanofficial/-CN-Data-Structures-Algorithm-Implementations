// cheak whether the data is repeating or not;

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
node *reverse(node *head)
{
    node *result = NULL;
    node *current = head;

    // Iterate through the list and move/insert each node
    // in front of the result list (like a push of the node)
    while (current != NULL)
    {
        // tricky: note the next node
        node *next = current->next;

        // move the current node onto the result
        current->next = result;
        result = current;

        // process next node
        current = next;
    }

    // fix head pointer
    head = result;
    return head;
}
bool ispalidrome(node *head)
{
    // int count=0;\

    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node *curr = head;
    int mid;
    int k = findlength(head);
    cout << k << endl;
    if (k % 2 == 0)
    {
        mid = k / 2;
    }
    else
    {
        mid = (k / 2) + 1;
    }

    node *head2 = NULL;

    for (int i = 1; i < mid; i++)
    {
        curr = curr->next;
    }
    head2 = curr->next;
    cout << head2->data << endl;
    cout << curr->data << endl;
    curr->next = NULL;
    print(head);
    node *h2 = reverse(head2);
    cout << " " << endl;
    print(h2);
    node *h1 = head;
    // // checking palindrome or not
    node *curr1 = h1;
    node *curr2 = h2;
    while (curr1 != NULL && curr2 != NULL)

    {
        if (curr1->data == curr2->data)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else
            return 0;
    }
    if (curr1 == NULL || curr2 == NULL)
    {
        return 1;
    }
}

int main()
{
    node *head = takeinput();
    // print(head);
    cout << " " << endl;
    // node *newhead=reverse(head);
    // print(newhead);
    // int i;

    // cout << "input element and index i at which you check" << endl;
    // cin >> i;
    // cout << findlength(head) << endl;
    int y = ispalidrome(head);
    if (y > 0)
    {
        cout << "true";
    }
    else
        cout << "false";

    return 0;
}