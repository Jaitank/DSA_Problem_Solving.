// Q. Here we have 0 and 1 in our array now we have to sort all zeroes to
// left and all 1 to right.

#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void Sort_01(int arr[],int size)
{
    int i =0;
    int j = size-1;
    while(i < j)
    {
        while(arr[i]==0){
            i++;
        }
        while(arr[j]==1)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
}

int main()
{
    cout<<"Enter size of array :";
    int size;
    cin>>size;
    int arr[100];
    cout<<"Enter elements of array"<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    Sort_01(arr,size);
    printArray(arr,size);
    return 0;
}
