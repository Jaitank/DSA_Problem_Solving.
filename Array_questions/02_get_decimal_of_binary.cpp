// Question :  Try to find decimal of given binary number.

#include<iostream>
#include<math.h>
using namespace std;

void binary_to_decimal(int n)
{
    
    int i = 0;
    int ans = 0;
    while(n!=0) // when number becomes 0 stop loop
    {
        
        int digit = n%10; // to get last digit because % --> remainder and if 101 % 10 then remainder is always last digit i.e. 1
        if(digit == 1) // binary contains only 0 and 1 and if we get digit as  1 then we have to make its iteration 'i' on power of 2
        {
            ans = ans + pow(2,i); //  power of 2 is calculated to find decimal to binary
            
            // cout<<"n is "<<n<<endl;        
        }
        n = n/10; // it remove last digit of number so that we can further calculated for remaining digits.
        i++; // iteration number increased by 1.
        
    }
    

    cout<<"ans is :"<<ans;
}

int main()
{
    int n;
    cout<<"Enter binary number to get is decimal :";
    cin>>n;

    binary_to_decimal(n);
    return 0;
}