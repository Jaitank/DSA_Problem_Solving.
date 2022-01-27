/*
We have two sorted array and we have to merge and store them in third array in sorted order.
for Eg :  A1 = [1,2,3,4,5]
          A2 = [3,5,6,7]
          we have to store them in third array in sorted array.
          A3 = [1,2,3,4,4,5,5,6,7]
*/
#include <bits/stdc++.h>
using namespace std;

void merge_two_sorted_array_in_3rd(int a[],int m, int b[], int n, int c[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    // two pointer approach; where one one pointer on both array and traverse 
    // while comparing both array's element with pointer, element which is smaller is copied to new array.
    while(i < m && j < n)  
    {
        if(a[i] < b[j])  
        {
           
            c[k++] = a[i++];        // element which is smaller is copied to new array.
            
        }
        else                   
        {
           
            c[k++] = b[j++];
        }
    }

    while(i < m)
    {
        c[k++] = a[i++];
    }

    while(j < n)
    {
        c[k++] = b[j++];
    }
}

void printArray(int c[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<c[i]<<" ";
    }
}
int main()
{
    int A1[] = {1,2,3,4,5};
    int m = sizeof(A1)/sizeof(A1[0]);
    int A2[] = {3,5,6,7};
    int n = sizeof(A2)/sizeof(A2[0]);
    int A3[n+m] = {};

    merge_two_sorted_array_in_3rd(A1,m,A2,n,A3);
    printArray(A3,n+m );

    return 0;
}