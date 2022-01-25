/* Here we have to search a value in a rotated sorted array.
 as we know in roated sorted array we always have pivot and by using it we ca easliy apply
 binary search in both sorted list
 Approach:  In a rotated sorted array we know we have two sorted lists say sorted List1 [0,(pivot-1)] and sorted List2[pivot,n-1]
 so if our target lies b/w arr[0] and arr[pivot -1] ==> binarySearch(sorted List1)
 and if our target lies b/w arr[pivot] and arr[n-1] ==> binarySearch(sorted List2)
 
 This will be our approach and for this we should have two function 
 1. BinarySearch()
 2. get_Pivot()
 */

#include<iostream>
using namespace std;

// Get pivot function ->

int get_Pivot(int arr[],int size)
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

// Binary Search function ->

int binarySearch(int arr[], int start, int end, int key) // Time complexity of O(log N) It follow Divide and Conqr method
{
    
    while (start <= end)
    {
        int mid = start + (end-start)/2; // we avoid here mid = (start + end)/2 because, if some whe                                     
        if (arr[mid] == key)         // int value is at it max then for both start and end then
        {                           // it exceeds size limit of int. so its good practice to use
            return mid;           // always mid = start + (end-start)/2.
        }

        else if ( arr[mid] < key)
        {
            start = mid+1;
        }
        else
        {
            end = mid -1;
        }
    }
    return -1;
}

int search_in_RoatedSortedArray(int arr[],  int size, int key)
{
    int pivot = get_Pivot(arr,size);
    if(key >= arr[pivot] && key <= arr[size-1]) // if our target lies b/w arr[0] and arr[pivot -1] ==> binarySearch(sorted List1)
    {
        return binarySearch(arr, pivot, size-1, key);
    }
    else                               // if our target lies b/w arr[pivot] and arr[n-1] ==> binarySearch(sorted List2)
    {
        return binarySearch(arr, 0, pivot-1, key);
    }

}

int main()
{
    int size;
    int arr[] = {12,14,15,2,5,7,8,9};
    size = sizeof(arr)/sizeof(arr[0]); // it will give us size of an array

    cout<<"Enter Elememt you want to search in array :";
    int key;
    cin>>key;

    cout<<"Your element is at index :"<<search_in_RoatedSortedArray(arr,size,key);
    return 0;
}