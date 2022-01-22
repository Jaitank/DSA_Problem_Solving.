/*
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.

Sample Input : 2 3 1 6 3 6 2  

Sample Output : 1

*/

#include<iostream>
using namespace std;

int main()
{
    int arr[7] = {2,3,4,6,3,6,2}; // 2,3,6 are twice times and 4 is single time so we need ans as 4.
    /*
    Brute force apporach:  count repeation of every value of array and return element which has count ==1;
    But this is not an optimised solution for that problem this can be optimised by using XOR - ^.
    Using XOR we can = 2 ^ 2 = 0 means it cuts the same values of if we XOR the whole elements with each other all twices are cutted and 
    single one remains becuase 0 ^ 3 = 3
    */
   int ans = 0;

   for (int i = 0; i<7; i++)
   {
       ans = ans ^ arr[i];
   }

   cout<<"Answer is :"<<ans;
    return 0;
}



