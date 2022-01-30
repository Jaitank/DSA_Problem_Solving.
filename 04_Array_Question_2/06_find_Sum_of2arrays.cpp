#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int num1 = 0;
    int num2 = 0;
    for (int i = n - 1, j = 0; i >= 0; i--, j++)       // take all element and make them one number: {1,2,3} => 123
    {

        num1 = (a[i] * pow(10, j)) + num1;
    }
    for (int i = m - 1, j = 0; i >= 0; i--, j++)   // do that for num2 also
    {

        num2 = (b[i] * pow(10, j)) + num2;
    }

    int sum = num1 + num2;                         // add num1 and num2 

    vector<int> ansSum;

    while (sum > 0)                        /// and store them in vector ans digit by digit.
    {

        int s = sum % 10;

        ansSum.insert(ansSum.begin(), s);
        sum = sum / 10;
    }
    return ansSum;
}

int main()
{

    // main code
    return 0;
}