#include<iostream>
using namespace std;

// Function to print Array
void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int binarySearch(int arr[], int size, int key) // Time complexity of O(log N) It follow Divide and Conqr method
{
    int start = 0;
    int end = size-1;
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

int main()
{
    int arr[100];
    int size;
    cout<<"Enter size :";
    cin>>size;
    cout<<"Enter elements of Array :"<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter Number you want to search in array :";
    int key;
    cin>>key;

    int ind = binarySearch(arr,size,key);

    cout<<"Your no. is at index :"<<ind;

    return 0;
}