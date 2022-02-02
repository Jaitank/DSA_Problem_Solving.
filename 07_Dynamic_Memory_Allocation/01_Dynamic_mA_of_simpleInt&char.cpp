#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i = 5; // this is static memory allocation, and its memory is allocated in stack.

    char ch = 'a';  // this is also static memory allocation, which memory is in stack.

    int *integer = new int; // new keyword allocated a memory in heap dynamically and throw address, and we store that address in pointer *integer

    char * chPointer = new char; // character size memory is allocated in heap.

    // this dynamically created memory would not automatically released like static, but we have to delete this manually like-
    delete integer;
    delete chPointer;

    // Now see how to allocate array in heap, or dynamic allocation of array.
    int n;
    cin >> n; // size of array we have to create, in runtime.
    
    //variable size array
    int* arr = new int[n]; // dynamic memory allocation, new int[n] throws address of first block and we have stored this in *arr.

    //takign inputn in aray
    for(int i=0; i<n; i++) {   
        cin >> arr[i];
    }

    // to release that array from heap -
    delete []arr;

    return 0;
}