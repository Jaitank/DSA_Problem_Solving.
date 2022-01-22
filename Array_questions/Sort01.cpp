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

/* Here we going to use two pointer apporach in which we place two pointer: one at start i.e, i and
another is at end i.e, j while arr[i]==0 then i++ and arr[j]==1 then j--; but when we see that 
arr[i] = 1 and arr[j] == 0 then at that iteration we swap them with each other, and it will sort 0 & 1.
we have to do that till i < j.
*/
void Sort_01(int arr[],int size)
{
    int i =0;
    int j = size-1;
    while(i < j)
    {
        while(arr[i]==0){
            i++;              // till we get arr[i] == 1, we have to make i++
        }
        while(arr[j]==1)
        {
            j--;            // till we get arr[j] == 0, we have to make j--
        }
        if(i<j)
        {
            swap(arr[i],arr[j]); // whenever starting pointer gets 1 and ending pointer 0, then
                                // we have to swap
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