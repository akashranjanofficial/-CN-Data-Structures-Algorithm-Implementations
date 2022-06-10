// concept of dynamic array in stack := jab array full ho jaye to uss array ka size double and copy all the data;

// Removing size constraint using dynamic array

#include <bits/stdc++.h>
using namespace std;
template <typename t>
class stackusingArray
{
private:
    int nextIndex;
    t *data;
    int capacity;

public:
    stackusingArray()
    { // default constructur for creating stack;
        data = new t[4];
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
    void push(t element)
    {
        if (nextIndex == capacity)
        {
            t *newdata = new t[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            capacity = capacity * 2;
            delete[] data;  // deallocting the data;
            data = newdata; // pointing new data to data;
        }

        data[nextIndex] = element;
        nextIndex++;
    }
    // delete the element;
    t pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
    // find top of element;
    t top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    stackusingArray<char> s;
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
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
}