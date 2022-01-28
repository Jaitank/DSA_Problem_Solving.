#include <bits/stdc++.h>
using namespace std;

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;

}

void reverseString(char name[], int size)
{
    int s = 0;
    int e = size-1;

    while(s<=e)
    {
        swap(name[s++],name[e--]);
    }
}

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

bool isPalindrome(char name[], int size)
{
    int s = 0, e = size-1;
    while(s<=e)
    {
        if(toLowerCase(name[s]) != toLowerCase(name[e]))
          return 0;
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}
int main()
{
    char name[20];
    cout<<"Enter your name :";
    cin>>name;
    cout<<"Your Name is "<<name<<endl;

    cout<<"Length of name is "<<getLength(name)<<endl;

    int length = getLength(name);

    reverseString(name,length);

    cout<<"Reverse is "<<name<<endl;

    // cout<<toLowerCase('J');

    cout<<"Our name is Palindrome or not :"<<isPalindrome(name,length);
    return 0;
}