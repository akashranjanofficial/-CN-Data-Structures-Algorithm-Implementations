/* concept of stack is 1-insert ->push()
  delete-> pop()
  access the top most element -> top()
  ==- ACCCESS THE SIZE OF STACK -> size()
  isEmpty()->check wheather the stack is empty or not

  RELATION BETWEEN RECURSSION AND STACK
   MAIN-> FACT(4)->FACT(3)->FACT(2)->FACT(1)->FACT(0)

   //stack using array
 STACK->>  LIFO ->LAST IN FIRST OUT (JO LAST ME GHUSSA WO 1ST ME BAHAR AYE GA)
   {
       FIFO _>FIRST IN FIRST OUT;
   }
*/
// CREATIG A STRUCTURE FOR STACK
// STACK USING ARRAY
#include <bits/stdc++.h>
using namespace std;
class stackusingArray
{
private:
    int nextIndex;
    int *data;
    int capacity;

public:
    stackusingArray(int totalsize)
    { // default constructur for creating stack;
        data = new int[totalsize];
        nextIndex = 0;
        capacity = totalsize;
    }
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        // if(nextIndex==0){
        //     return true;

        // }else return false;
        return nextIndex == 0;
    }
    // insert a element in stack
    void push(int element)
    {
        if (nextIndex != capacity)
        {
            data[nextIndex] = element;
            nextIndex++;
        }
        else
        {
            cout << "stack full" << endl;
        }
    }
    // delete the element;
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    // find top of element;
    int top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    stackusingArray s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
}
