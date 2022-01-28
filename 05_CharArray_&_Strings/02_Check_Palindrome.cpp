/*
Problem Statement
You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.
Note :
String 'S' is NOT case sensitive.
Example :
Let S = “c1 O$d@eeD o1c”.
If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is
 a palindrome. Hence, the given string is also a palindrome.
*/
#include <bits/stdc++.h>
using namespace std;

// This function will tell you is your character is valid or not according to question.
bool isValid(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    return 0;
}

// this will convert you character to lower case
char toLowerCase(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }

    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
// This will tell you is your string is palindrome or not ( palindrome:  string which reverse is also same like NooN = reverse(NooN) = NooN)
bool isPalindrome(string temp)
{
    int s = 0, e = temp.length()-1;
    while(s<=e)
    {
        if(toLowerCase(temp[s]) != toLowerCase(temp[e]))
          return 0;
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}
bool checkPalindrome(string s)
{
    // Remove all symbols and whitespaces from our string and save the string with valid character in string temp
    string temp = {};
    
   for ( int j = 0; j < s.length(); j++)
   {
        if(isValid(s[j]))
    {
            temp.push_back(s[j]);
    }
   }
    
    // Now in temp our string with valid character are ready, now we have to make them all to lower case
    for ( int i = 0; i<temp.length(); i++)
    {
        temp[i]= toLowerCase(temp[i]);
    }
    
    // Now check palindorme with another function
    return isPalindrome(temp);
    
    
    
}


int main()
{
    
    return 0;
}