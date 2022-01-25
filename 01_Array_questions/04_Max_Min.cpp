// Q: In this we have to find Maximum and Minimum element from a given array.

#include <iostream>
using namespace std;

int get_Max(int arr[], int size)
{
    int maxium = INT32_MIN; //  INT32_MIN is smallest value, with which we intialised our maximum variable.
    for (int i = 0; i < size; i++)
    {
        maxium = max(maxium, arr[i]); //  It compares each array value in every iteration with maximum variable and  update max out of it.
    }

    return maxium;
}

int get_Min(int arr[], int size)
{
    int minimum = INT32_MAX; //  INT32_MAX is largest value, with which we intialised our minimum variable..
    for (int i = 0; i < size; i++)
    {
        minimum = min(minimum, arr[i]); //  It compares each array value in every iteration with minimum variable and  update min out of it.
    }

    return minimum;
}

int main()
{
    int n;
    cout << "Enter NO. of elemets in array :";
    cin >> n;
    int arr[n]; //  it is not a good practice to give a variable in arr[n] like this but we are doing here just for this small problem.
    cout << "Enter array elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maximun = get_Max(arr, n);

    cout << "Maxium value from array is :" << maximun << endl;

    int minimum = get_Min(arr, n);

    cout << "Minimum value from array is :" << minimum << endl;

    return 0;
}
