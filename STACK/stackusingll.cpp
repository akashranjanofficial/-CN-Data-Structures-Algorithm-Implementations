// lets implement stack using linked list;
#include <bits/stdc++.h>
using namespace std;
template <typename t>
class node
{
public:
    t data;
    node<t> *next;
    // constructor
    node(t data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename t>
class Stack
{
    node<t> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }
    int getsize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
     void push(t element)
    {
        node<t> *newnode = new node<t>(element);
        /*if (head == NULL)
        {

            head = newnode;
            tail = newnode;
        }
        else
        {

            newnode->next = head;
            head = newnode;
        }
        */
        // better way of handling;
        newnode->next = head;
        head = newnode;
        size++;
    }

    t pop()
    {
        if(isEmpty())
        {
            return 0;
        }
        t popdata = head->data;
        node<t> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return popdata;
    }
    t top()
    {
        if(isEmpty())
        {
            return 0;
        }
        return head->data;
    }
   
};

int main()
{
    Stack<char> s;
    s.push('a');
    s.push('k');
    s.push('a');
    s.push('s');
    s.push('h');

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.getsize() << endl;
    cout << s.isEmpty() << endl;
}