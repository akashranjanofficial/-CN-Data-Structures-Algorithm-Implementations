#include <stdio.h>
#include <stdlib.h>
int i,j;
int* fill(int n)
{
int * arr;
arr = (int * ) malloc(n * sizeof(int));
for (i = 0; i < n; i++)
arr[i] = rand() % 10000;
return arr;
}
int insertionSort(int arr[], int n)
{
int i, key, j, count=0;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
j = j - 1;
count+=2;
}
arr[j + 1] = key;
count++;
}
return count+1;
}
int main()
{
int steps_random,steps_sorted,steps_reverse;
int a=0,b=0,c=0;
for(j =0; j<500; j++)
{
int * arr = fill(200);
int * random = fill(200);
steps_sorted = insertionSort(arr,200);
steps_random = insertionSort(random,200);
int rev[200];
for(i=0;i<200;i++)
{
rev[i] = arr[200-1-i];
}
steps_reverse = insertionSort(rev,200);
a+=steps_random;
b+=steps_sorted;
c+=steps_reverse;
}
printf("\nFOR 500 ITERATION OF 200 SIZE ARRAY STEP COUNT ARE");
printf("\n\tsorted : %d\n\trandom : %d\n\treverse : %d\n\t",b/500,a/500,c/500);
for(j =0; j<1000; j++)
{
int * arr = fill(200);
int * random = fill(200);
steps_sorted = insertionSort(arr,200);
steps_random = insertionSort(random,200);
int rev[200];
for(i=0;i<200;i++)
{
rev[i] = arr[200-1-i];
}
steps_reverse = insertionSort(rev,200);
a+=steps_random;
b+=steps_sorted;
c+=steps_reverse;
}
printf("\nFOR 1000 ITERATION OF 200 SIZE ARRAY STEP COUNT ARE");
printf("\n\tsorted : %d\n\trandom : %d\n\treverse : %d\n\t",b/1000,a/1000,c/1000);
for(j =0; j<10000; j++)
{
int * arr = fill(200);
int * random = fill(200);
steps_sorted = insertionSort(arr,200);
steps_random = insertionSort(random,200);
int rev[200];
for(i=0;i<200;i++)
{
rev[i] = arr[200-1-i];
}
steps_reverse = insertionSort(rev,200);
a+=steps_random;
b+=steps_sorted;
c+=steps_reverse;
}
printf("\nFOR 10000 ITERATION OF 200 SIZE ARRAY STEP COUNT ARE");
printf("\n\tsorted : %d\n\trandom : %d\n\treverse : %d\n\t",b/10000,a/10000,c/10000);
}