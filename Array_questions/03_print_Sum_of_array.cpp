// Q: Print sum of elements in given array

#include<iostream>
using namespace std;

int main()
{
    int size;
    cout<<"Enter size of array :";
    cin>>size;
    cout<<"Enter array elements : "<<endl;
    int arr[100];
    for (int i =0; i<size; i++)
    {
        cin>>arr[i];
    }
    int sum = 0;

    for (int i =0 ; i<size; i++)
    {
        sum = sum + arr[i];
    }

    cout<<"Sum of elements of array is : "<<sum;
    return 0;
}
