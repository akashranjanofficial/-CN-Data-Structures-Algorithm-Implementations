// concept of dynamic array in stack := jab array full ho jaye to uss array ka size double and copy all the data;

// Removing size constraint using dynamic array

#include <bits/stdc++.h>
using namespace std;
class stackusingArray
{
private:
    int nextIndex;
    int *data;
    int capacity;

public:
    stackusingArray()
    { // default constructur for creating stack;
        data = new int[4];
        nextIndex = 0;
        capacity = 4; // randomly select kr liya size of array
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
        if (nextIndex == capacity)
        {
            int *newdata = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
               newdata[i]=data[i];
            }
            capacity=capacity*2;
            delete[] data;//deallocting the data;
            data=newdata; //pointing new data to data;
            
        }
        
        data[nextIndex] = element;
        nextIndex++;
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
    stackusingArray s;
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