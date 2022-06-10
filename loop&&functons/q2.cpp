/*Terms of AP
Send Feedback
Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
Input format :
Integer x
Output format :
Terms of series (separated by space)
Constraints :
1 <= x <= 1,000
Sample Input 1 :
10
Sample Output 1 :
5 11 14 17 23 26 29 35 38 41
Sample Input 2 :
4
Sample Output 2 :
5 11 14 17

*/

#include <iostream>
using namespace std;

void printseries(int x)
{
    int n = 1;
    int z = 0;
    while (true)
    {
        int y;
        y = 3 * n + 2;
        if (z == x)
        {
            break;
        }

        if (y % 4 != 0)
        {
            cout << "THE TERMS WHICH ARE NOT MULTIPLE OF 4 ARE :- "
                 << " " << n << "  "
                 << "term is " << endl;
            cout << " " << y << " " << endl;
            z = z + 1;
        }
        else
        {
            if (y % 4 == 0)
            {
                cout << " NUMBER FOUND MULTIPLE OF 4 are :-" << n << "terms" << endl;
                cout << " " << y << " " << endl;
            }
        };
        n++;
    }
}
int main()
{
    int x;
    cout << "ENTER THE VALUE OF x";

    cin >> x;

    printseries(x);

    return 0;
}
