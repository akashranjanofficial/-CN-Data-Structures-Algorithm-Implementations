#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
int Reversesorted(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int Partation(int arr[], int start, int end)
{
    int i, index = start, temp;
    for (i = start; i < end; i++)
    {
        if (arr[i] < arr[end])
        {
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
            index++;
        }
    }
    temp = arr[index];
    arr[index] = arr[end];
    arr[end] = temp;
    return index;
}
int Quicksort(int arr[], int start, int end)
{
    if (end > start)
    {
        int index = Partation(arr, start, end);
        Quicksort(arr, start, index - 1);
        Quicksort(arr, index + 1, end);
    }
}
int Merge(int arr[], int start, int mid, int end)
{
    int i, j, k, temp, Ln, Rn;
    Ln = mid - start + 1;
    Rn = end - mid;
    int Larr[Ln], Rarr[Rn];
    for (i = 0; i < Ln; i++)
        Larr[i] = arr[start + i];
    for (j = 0; j < Rn; j++)
        Rarr[j] = arr[mid + 1 + j];
    k = start;
    i = 0;
    j = 0;
    while (i < Ln && j < Rn)
    {
        if (Larr[i] < Rarr[j])
        {
        }
        else
        {
            arr[k] = Larr[i];
            i++;
            arr[k] = Rarr[j];
            j++;
        }
        k++;
    }
    while (i < Ln) // copying the elements of Larr[]
    {
        arr[k] = Larr[i];
        i++;
        k++;
    }
    while (j < Rn)
    {
        arr[k] = Rarr[j]; // copying the elements of Rarr[] j++;
        k++;
    }
}
int Mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        Mergesort(arr, start, mid); // sort start, end , mid Mergesort(arr,mid+1,end); Merge(arr,start,mid,end);
    }
}
int main() // main function
{

    printf("\n\n===================for mergesortt=============================\n");
    int size_924[4];
    size_924[0] = 500;
    size_924[1] = 10000;
    size_924[2] = 50000;
    size_924[3] = 100000;
    int j;
    printf("\n\nakash ranjan. Roll- 1905924\n\n");
    printf("\n In the case of random values-:\n");
    for (j = 0; j < 4; j++)
    {
        int *arr;
        int i;
        clock_t start, end;
        arr = (int *)malloc(size_924[j] * sizeof(int)); // memory allocation for random values
        for (i = 0; i < size_924[j]; i++)
        {
            arr[i] = rand() % 1000;
        }
        start = clock();
       // printf("\n\nfor mergesort\n");
        Mergesort(arr, 0, (size_924[j] - 1));
        // printf("\n\nfor quicksort\n");
        // Quicksort(arr, 0, (size_924[j] - 1));
        end = clock();
        double time;
        time = ((double)(start - end)) / CLOCKS_PER_SEC;
        printf("\nFor n=%d\ttime=%f", size_924[j], time);
        // free(arr);
    }
    printf("\n\n In the case of sorted array-:\n");
    for (j = 0; j < 4; j++)
    {
        int *arr;
        int i;
        clock_t start, end;
        arr = (int *)malloc(size_924[j] * sizeof(int)); // memory allocation for sorted array
        arr[0] = rand() % 10;
        for (i = 1; i < size_924[j]; i++)
        {
            arr[i] = arr[i - 1] + (rand() % 1000);
        }
        start = clock();
        //printf("\n\nfor mergesort\n");
         Mergesort(arr, 0, (size_924[j] - 1));
        // printf("\n\nfor quicksort\n");
        // Quicksort(arr, 0, (size_924[j] - 1));
        end = clock();
        double time;
        time = ((double)(start - end)) / CLOCKS_PER_SEC;
        printf("\nFor n=%d\ttime=%f", size_924[j], time);
        printf("\t\t%f sec", time);
        // free(arr);
    }
    printf("\n\n In the case of Reverse sorted array-:\n");
    for (j = 0; j < 4; j++)
    {
        int *arr;
        int i;
        clock_t start, end;
        arr = (int *)malloc(size_924[j] * sizeof(int)); // memory allocation for reverse sorted array
        arr[size_924[j] - 1] = rand() % 10;
        for (i = (size_924[j] - 2); i >= 0; i--)
        {
            arr[i] = arr[i + 1] + (rand() % 1000);
        }
        start = clock();

       // printf("\n\n for mergesort\n");
        Mergesort(arr, 0, (size_924[j] - 1));
        // Reversesorted(arr,0,(size_924[j]-1));
        // printf("\n\nfor quicksort\n");
        // Quicksort(arr, 0, (size_924[j] - 1));
        end = clock();
        double time;
        time = ((double)(start - end)) / CLOCKS_PER_SEC;
        printf("\nFor n=%d\ttime=%f", size_924[j], time);
        printf("\t\t\t%f sec\n\n", time);
        //free(arr);
    }
  printf("\n\n===================for quicksort=============================\n");
    int size[4];
    size[0] = 5000;
    size[1] = 10000;
    size[2] = 50000;
    size[3] = 1000000;
    int p;
    printf("\t\tFor the random\t\tFor the Sort Array\t\tFor the Reverse sorted Array");
    for (p = 0; p < 4; p++)
    {
        int *arr11;
        int i;
        clock_t start, end;
        arr11 = (int *)malloc(size[p] * sizeof(int));
        for (i = 0; i < size[p]; i++)
        {
            arr11[i] = rand() % 1000;
        }
        start = clock();
        Quicksort(arr11, 0, (size[p] - 1));
        end = clock();
        double time;
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\nFor n=%d\t%f sec", size[p], time); //for sorted array start=clock(); Quicksort(arr,0,(size[j]-1)); end=clock(); time=((double)(end-start))/ CLOCKS_PER_SEC; printf("\t\t%f sec",time); //for reverse sorted
        Reversesorted(arr11, 0, (size[p] - 1));
        start = clock();
        Quicksort(arr11, 0, (size[p] - 1));
        end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\t\t\t%f sec", time);
        free(arr11);
    }

}
