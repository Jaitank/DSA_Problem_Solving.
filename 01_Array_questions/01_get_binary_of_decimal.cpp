// Question :  Try to find binary output of given decimal number.

#include<iostream>
#include <math.h>
using namespace std;

void get_binary(int number)
{

    int ans = 0;
    int i = 0;
    while (number !=0) //  loop is stop when number becomes 000 by right shift. it means we have drawned out req. binary number.
    {
        int bit = number & 1; //  By this decimals last digit in binar means 5 in binary is 101 so 1 is drawn out ans saved in bit 
        
        ans = (bit * pow(10,i)); //  according to bits place value which is decided by 'i' if i = 1 and bit is also 1 so : 1 * 10^1 = 10
        // if bit is 1 and i is 2 so 1 * 10^2 = 100 thats how we calculated binary and saves it into and integer ans.  
        
        number  = number >> 1; // now nuber is right shift by 1 means 101 is right shift by 1 and becomes 101-->001 
        // when again it right shift by 1 then it becomes 001-->000.

        i++;       // i is incerased by 1 in every iteration to count plave value.
    }   
    cout<<ans;

}

int main()
{
    int n;
    cout << "Give number to get its binary :";
    cin>>n;

    get_binary(n);


    return 0;
}
