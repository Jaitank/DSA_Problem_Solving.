// Merge two sorted array in 1st array in sorted order.
#include <bits/stdc++.h>
using namespace std;

// It is same as Merge two sorted array in third one. only the difference is we have to merge and store in 1st array
// thats why we have start filling in first array from end.

void Merge_sorted_arrays_in1stone(int a[], int m, int b[], int n)
{

    int i = m-1;
    int j = n-1;     
    int k = m+n-1;

    while( i >= 0 && j >= 0 )
    {
        if(a[i] < b[j])
        {
            a[k--] = b[j--];
        }
        else
        {
            a[k--] = a[i--];
        }
    }
    while( j >= 0)
    {
        a[k--] = b[j--];
    }

    for ( int i =0; i < n+m; i++)
    {
        cout<<a[i]<<" ";
    }

}

  

int main()
{
    int a[] = {1,2,3};
    int m = sizeof(a)/sizeof(a[0]);

    int b[] = {2,5,6};
    int n = sizeof(b)/sizeof(b[0]);

    Merge_sorted_arrays_in1stone(a,m,b,n);

    return 0;
}