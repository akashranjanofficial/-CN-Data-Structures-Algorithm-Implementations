#include <bits/stdc++.h>
using namespace std;
void printhaspath(int **input, int n, int **solution, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        solution[x][y] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solution[i][j]<<" ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    if (x < 0 || y < 0 || x >= n || y >= n || input[x][y] == 0 || solution[x][y] == 1)
    {
        return;
    }
    solution[x][y] = 1;

    printhaspath(input, n, solution, x - 1, y);
    printhaspath(input, n, solution, x + 1, y);
    printhaspath(input, n, solution, x, y - 1);
    printhaspath(input, n, solution, x, y + 1);
    solution[x][y] = 0;
}
bool haspathhelper(int **input, int n, int **solution, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        return true;
    }
    if (x < 0 || y < 0 || x >= n || y >= n || input[x][y] == 0 || solution[x][y] == 1)
    {
        return 0;
    }
    solution[x][y] = 1;
    if (haspathhelper(input, n, solution, x - 1, y))
    {
        return true;
    }
    if (haspathhelper(input, n, solution, x + 1, y))
    {
        return true;
    }
    if (haspathhelper(input, n, solution, x, y - 1))
    {
        return true;
    }
    if (haspathhelper(input, n, solution, x - 1, y + 1))
    {
        return true;
    }
    solution[x][y] = 0;
    return false;
}
bool haspath(int **arr, int n)
{
    int **solution = new int *[n]; //we created array of pointers to store the every column we are maintaining the solution matrix to mantain what we have visited
    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solution[i][j] = 0;
        }
    }
    printhaspath(arr, n, solution, 0, 0);
    return true;
    // return haspathhelper(arr, n, solution, 0, 0);
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n]; //we created array of pointers to store the every column
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << haspath(arr, n) << endl;
}