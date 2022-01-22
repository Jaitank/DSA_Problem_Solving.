// You are given an array ARR of size N containing each number between 1 and N - 1 at least once. There is a single
// integer value that is present in the array twice. Your task is to find the duplicate integer value present in the
//  array.
// Eg :  Input value : 6 3 1 5 4 3 2
//       Output value : 3               bcoz 3 is twice in array

#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {6, 3, 1, 5, 4, 3, 2};
    /*
    Brute force approach :  We have to count occurence of all elements one by one
    then we will check which one has occurence count = 2 and we get answer.
    but there is an optimised solution too, which is -> as we know XOR will cancel out same numbers.
    and if we XOR that elements which is(1....N-1 in which X is repeating itself twice) XOR (1....N-1) in which
    X also occurs single times then, all the same numbers are cancel out and from 1st series we get the number
    which is twice in series.
    */
    int ans = 0;
    for (int i = 0; i < 7; i++)
    {
        ans = ans ^ arr[i]; // at the end of this loop this ans contains XOR of all elements of 1st list
                            // ans = (1^2^....X^X...^N-1)
    }

    // Now we have to XOR that ans with list = 1.....N-1

    for (int i = 1; i < 7; i++)
    {
        ans = ans ^ i; // Now we are XOR ing ans with 1....N-1 (i) and by this we get that repeating element
                       //    at last in ans
    }

    cout << ans;

    return 0;
}
