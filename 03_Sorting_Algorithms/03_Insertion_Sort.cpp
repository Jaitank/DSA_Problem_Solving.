// Insertion Sort: 

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,-234,13,15,3,45,6,23,-23,2,235};
    int size = sizeof(arr)/sizeof(arr[0]);

    // In insertion sort we have to take element one by one and then arrange that element in its correct position in sorted part
    // Lets suppose  i = 0, is sorted one part of that array and now we have to take its next element and compare that in sorted
    // part and then placed it to its correct position.

    for (int i = 1; i < size; i++)
    {
        int temp = arr[i]; // Save that in temp variable so that we can compare it in sorted part and if want then we can shift 
                           // sorted part without loosing our arr[i] value.

        int j = i -1; // we have to check compare that element, from previous postion of 'i'(from where sorted part started) 
                        //  thats why we initialse our j from i -1 and we have to check till 0 th index.

        while( j >= 0)
        {
            if(arr[j] > temp)     // while checking, if element is larger than our temp or arr[i] for which we are checking 
            {                     
                arr[j+1] = arr[j]; // then we have to shift that element to right side 
            }
            else{
                break;
            }
            j--;                  

        }
        arr[j+1] = temp;  //  when arr[j]'s value is less than our temp then insert element in its next position
        
    }

    // Printing array
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}