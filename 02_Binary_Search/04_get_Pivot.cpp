// Here we have to find pivot 
// Using binary Search for O(logN)

#include<iostream>
using namespace std;

int findPivot(int arr[],int size)
{
    int s =0; // start
    int e = size-1; //end
    int mid = s + (e-s)/2;
    while(s<e)
    {
        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
        
    }
    return s;
}

int main()
{
    int size = 6;
    int arr[100] = {12,14,3,4,7,9};
    int pivot;

    pivot = findPivot(arr,size);

    cout<<"Pivot is : "<<pivot;

    return 0;
}