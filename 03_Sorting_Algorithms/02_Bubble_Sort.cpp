/*
Bubble Sort : Repeatedly swap two adjacent elements if they are in wrong order. By this one iteration, max one shifted
to the last, now lefting that last one same process we have to repeat for rest array

In Bubble sort ith largest element is shift towards its right place in ith round.
means -> 1st max element shift at right place of it in 1st round when i = 1,
         2nd max element shift at right place of it in 2nd round when i = 2
         ans so on.

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{

    int arr[] = {64, 25, 12, 22, 11, -1, 4, 52, 3, -234};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++)
    {
        bool swapped = false; // For optimising the solution, if there will no swap occur in next loop then break the loop becuase our 
                              //array is already sorted.

        for (int j = 0; j < n - i; j++) //  Here n-i as condition, because in every iteration we have to traverse of (n-i), for i = i we have to traverse
        {                               // n-1, for i =2 we have to traverse n -2 and so on thats why in first loop i in intialsed by 1 and
            if (arr[j] > arr[j + 1])    // in 2nd loop j < n-i condition is being applied.
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false) // if it true means now our array is sorted so need to done more extra work
        {
            break;      
        }

    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
    

    // Time Complexity in best case ==> when array is already sorted then ==> swapped becomes false and loop breaks so ==> O(n)

    // Time Complexity in worst case ==> When reverse sorted array is present then O(n^2).
}
