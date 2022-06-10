// Code: Merge Two Sorted LL
// Send Feedback
// You have been given two sorted(in ascending order) singly linked lists of integers.
// Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
// Note :
// Try solving this in O(1) auxiliary space.

// No need to print the list, it has already been taken care.
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space.

// The second line of the input contains the elements of the second sorted singly linked list separated by a single space.
// Remember/Consider :
// While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
// Output :
// For each test case/query, print the resulting sorted singly linked list, separated by a single space.

// Output for every test case will be printed in a seperate line.
// Constraints :
// 1 <= t = 10^2
// 0 <= N <= 10 ^ 4
// 0 <= M <= 10 ^ 4
// Where N and M denote the sizes of the singly linked lists.

// Time Limit: 1sec
// Sample Input 1 :
// 1
// 2 5 8 12 -1
// 3 6 9 -1
// Sample Output 1 :
// 2 3 5 6 8 9 12
// Sample Input 2 :
// 2
// 2 5 8 12 -1
// 3 6 9 -1
// 10 40 60 60 80 -1
// 10 20 30 40 50 60 90 100 -1
// Sample Output 2 :
// 2 3 5 6 8 9 12
// 10 10 20 30 40 40 50 60 60 60 80 90 100

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
node *returnmerged(node *h1, node *h2)
{
    node *fh = NULL; //
    node *ft = NULL; //final head;
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }
    if (h1->data <= h2->data)
    {
        fh = h1;
        ft = h1;
        h1=h1->next;
    }
    if (h1->data <= h2->data)
    {
        fh = h2;
        ft = h2;
        h2=h2->next;
    }
    while (h1 != NULL && h2 != NULL)

    {

        if (h1->data <= h2->data)
        {
            ft->next = h1;
            ft = h1;
            h1 = h1->next;
        }
        else
        {
            ft->next = h2;
            ft = h2;
            h2 = h2->next;
        }
    }
    if (h1 != NULL)
    {
        ft->next = h1;
        ft = h1;
    }
    if (h2 != NULL)
    {
        ft->next = h2;
        ft = h2;
    }
    return fh;
}
int main()
{
    node *head1 = takeinput();
    node *head2 = takeinput();
    node *head = returnmerged(head1, head2);
    print(head);

    return 0;
}