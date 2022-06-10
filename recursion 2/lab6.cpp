#include <bits/stdc++.h>
using namespace std;
#define ll long long
//function to sort the vector based on the fraction we have calculated
bool sortFraction(pair<int, float> f1, pair<int, float> f2)
{
    return f1.second > f2.second;
}
int main()
{
    int n_270; // no of object
    cout << "Enter no of input : ";
    cin >> n_270;
    int c; // capacity of the bag
    cout << "Enter capacity : ";
    cin >> c;
    int value[n_270], weight[n_270]; //value and weight of each object
    for (int i = 0; i < n_270; i++)
    {
        value[i] = rand() % 50; //taking random value
    }
    for (int i = 0; i < n_270; i++)
    {
        weight[i] = rand() % 10; //taking random value
    }
    cout << "\nAll the Items : \n";
    for (int i = 0; i < n_270; i++)
    {
        cout << "\nvalue : " << value[i] << " weight : " << weight[i];
    }
    //fraction is vector which contains pair, first is index and second is the fraction value/weight
    vector<pair<int, float>> fraction_270;
    for (int i = 0; i < n_270; i++)
    {
        fraction_270.push_back(make_pair(i, value[i] / (float)weight[i]));
    }
    sort(fraction_270.begin(), fraction_270.end(), sortFraction); //sorting the fraction on the basis of value/weight
    int netValue_270 = 0;
    cout << "\n\nItems we can get : \n\n";
    for (auto it : fraction_270)
    {
        int i = it.first; //index where the actual object is situated
        int val = value[it.first];
        int wei = weight[it.first];
        if (c - wei < 0) //if the weight is higher than capacity than we will check next item
        {
            continue;
        }
        c = c - wei;
        cout << "value : " << val << " weight : " << weight[it.first] << "\n";
        netValue_270 += val; //calculating net value
    }
    cout << "\n\nNet Value : " << netValue_270; //printing net value
    return 0;
}