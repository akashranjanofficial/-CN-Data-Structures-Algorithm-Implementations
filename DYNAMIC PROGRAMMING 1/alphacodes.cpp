#include <bits/stdc++.h>
using namespace std;

int numcodes(int *n, int size)
{
    //base case
    if (size == 1)
    {
        return 1;
    }
    if (size == 0)
    {
        return 1;
    }
    int output = numcodes(n, size - 1) //piche se reduce kr diya no ko
        if (output[size - 2] * 10 + output[size - 1] <= 26)
    {
        output += numcodes(n, size - 2);
    }
    return output;
    //ye code fas jaye ga kyu ki yaha fibonici wala problem ha kiya hua kam ham dubara kr rahe ha so problem ha
}
int numcodes(int *n, int size, int *arr)
{
    //base case
    if (size == 1)
    {
        return 1;
    }
    if (size == 0)
    {
        return 1;
    }
    if (arr[size] > 0)
    {
        return arr[size];
    }

    int output = numcodes(n, size - 1) //piche se reduce kr diya no ko
        if (output[size - 2] * 10 + output[size - 1] <= 26)
    {
        output += numcodes(n, size - 2);
    }
    arr[size] = output;
    return output;
}
//arr ko shru se fill krne ke liye itterative solution ha
int num_codes_i(int *input, int size)
{
    int *output = new int[size + 1];
    output[0] = 1;
    output[1] = 1;

    for (int i = 2; i <= size; i++)
    {
        output[i] = output[i - 1];
        if (input[i - 2] * 10 + input[i - 1] <= 26)
        {
            output[i] += output[i - 2];
        }
    }
    int ans = output[size];
    delete[] output;
    return ans;

    int main()
    {

        return 0;
    }