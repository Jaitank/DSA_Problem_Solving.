// Q: Swap alternates index values of given array
#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void swap_alternate(int arr[], int size)
{
    for (int i = 0; i < size-1 ; i+=2)
    {
        swap(arr[i],arr[i+1]);
    }
}

int main()
{
    int size;
    cout<<"Enter size of array :";
    cin>>size;
    int arr[100];
    cout<<"Enter elements of array :"<<endl;
    for(int i =0 ; i<size; i++)
    {
        cin>>arr[i];
    }

    cout<<"Array is :";
    printArray(arr,size);
    cout<<"Array after swaping of alternates is :";
    swap_alternate(arr,size);
    printArray(arr,size);

    return 0;
}
