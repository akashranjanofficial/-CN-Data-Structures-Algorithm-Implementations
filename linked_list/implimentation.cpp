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
// this is taking input using current variable and we are traversing all the linked list
// this takes the order of n^2; which is really bad we have to improve all that complixity
// how we can do it ?here comes the concept of tail in the linked list;
/*node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
                        }
            current->next = newnode;
        }
        cin >> data;
    }
    return head;
}
*/

// lets see concept of tail in the linked list;
// this will be in order of o(n)
//============== thanks this is it what is it  ============================================================
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

// printing ith node in linked list ;
int print_ith(node *head, int i)
{

    node *curr = head;
    int ithelement = 0;
    int count = 1;
    int length = findlength(head);

    if (i > length)
    {
        return -1;
    }
    else
    {
        while (count < i && curr != NULL)
        {
            curr = curr->next;
            count++;
        }
    }
    ithelement = curr->data;
    return ithelement;
    // cout << "the ith element is ::=" << ithelement << " " << endl;
}
// function to insert a node in ith position;
node *insert_a_node(node *head, int element, int index)
{
    node *curr = head;
    node *newnode = new node(element);
    int count = 1;
    if (index == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }

    while (curr != NULL && count < index)
    {
        curr = curr->next;
        count++;
    }
    if (curr != NULL)
    {
        node *temp = curr->next;
        curr->next = newnode;
        newnode->next = temp;
        return head;
    }
}

// delete a node at ith position
node *deleteNode(node *head, int pos)
{

    // we have to do one more check to confirm that n should not be more than
    // size of linked list
    if (findlength(head) < pos)
    {
        cout << "Invalid n; n doesnot exit in current linked list" << endl;
        return head;
    }
    if (head == NULL)
    {
        return head;
    }

    if (pos == 0)
    {
        return head->next;
    }

    node *curr = head;
    int currPos = 0;

    while (curr != NULL && currPos < pos - 1)
    {
        ++currPos;
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL)
    {
        return head;
    }

    curr->next = curr->next->next;

    return head;
}
//deletel a node recursivelu
node *deletenoderecursiverly(node * head,int pos)
{
    node * curr=head;
    //base case;
    if (pos==0)
    {
        head=head->next;
        delete curr;
        return head;
    }
    node *newnode=deletenoderecursiverly(head->next,pos-1);
    head->next=newnode;
    return head;
    
}
int main()
{ /*//STATICALLY
    node K1(1);
    node K2(2);
    node K3(3);
    node *head = &K1;
    K2.next=&K3;


    K1.next = &K2;
    cout << head->next->data;

    //DYNAMICALLY CREATING LINKED LIST
    node *k4=new node(10);
    node *k5=new node(20);
    k4->next=k5;
    k2.next=k4;
    */

    // lets create a linked list of 5 nodes,=1,2,3,4,5
    // lets create dynamiclly and statically
    /* node *n1=new node(1);
   node *n2=new node(2);
   node *n3=new node(3);
   node *n4=new node(4);
   node *n5=new node(5);
   node * head=n1;
   node * tail=n5;
   n1->next=n2;
   n2->next=n3;
   n3->next=n4;
   n4->next=n5;
   //printing complete linked list
   print(head);
   */
    node *head = takeinput();
    print(head);

    // int i;

    // cout << "input index i" << endl;
    // cin >> i;
    // cout << " "
    //      << " " << print_ith(head, i) << endl;
    // cout << " "
    //      << " And the length of the linked list is:::::==  " << findlength(head) << " " << endl;

    int element;
    int i;

    cout << "input element and index i at which you wnt to delete" << endl;
    cin >> i;
   // node *newhead = deleteNode(head, i);
   node *newhead=deletenoderecursiverly(head,i);
    print(newhead);

    return 0;
}
