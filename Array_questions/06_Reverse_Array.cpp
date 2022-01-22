// Q. Reverse given array.

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void Reversing_array(int arr[], int n)
{
    // By applying two pointer approach
    int s = 0; // set starting index
    int e = n - 1; // set ending index
    while (s < e) // loop is stop when s is large than e 
    {
        swap(arr[s], arr[e]); // starting index's value replaces with ending index's value
        s++; 
        e--;
    }
}

int main()
{
    cout << "Enter size of array : ";
    int size;
    cin >> size;

    cout << "Enter array elements  :" << endl;
    int arr[100];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    Reversing_array(arr, size);
    printArray(arr, size);

    return 0;
}
