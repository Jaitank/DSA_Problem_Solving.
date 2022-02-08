#include <bits/stdc++.h>
using namespace std;

string convert2binary(long long N) // here we convert a number to binary and then saves it in string.
{
    int i;
    string str = "";
    while (N != 0) // this convert N to its binary and store it in string
    {              // so that we can check palindrome
        i = N % 2;
        N = N / 2;
        str.push_back(i);
    }

    return str;
}

bool checkPalind_S(string &str, int i) // using formula size - i - 1 (more optimised)
{
    // base condition
    if (str[i] != str[str.size() - i - 1])
    {
        return 0;
    }
    if (i > str.size() - i - 1)
    {
        return 1;
    }

    return checkPalind_S(str, ++i);
}

bool checkPalindrome_1(long long N)
{
    string binary_str = convert2binary(N);
    return checkPalind_S(binary_str, 0);
}

// Small Function to do that all stuff by using loop more optimised
bool checkPalindrome_2(long long N)
{
    string s="";
    int r;
    while(N>0)
    {
        r=N%2;
        N=N/2;
        s.push_back(r);
    }
    int i=0;
    int j=s.length()-1;
    while(i<=j)
      if(s[i++]!=s[j--]) return 0;
    return 1; 
}

int main()
{
    
    return 0;
}