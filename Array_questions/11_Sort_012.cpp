// Q. Here we have 0,1 and 2 in our array in O(n)

#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

/* 
In this apporach first we count no of zero, one and two and then we push them with sorting in array again.
*/
void Sort_012_Algo1(int arr[], int n) // It has Runtime = 1081ms
{
   int zero = 0;
   int one = 0;
   int two = 0;
   int j = 0;
    for(int i=0; i<n; i++)      
    {
        if(arr[i]==0)
            zero+=1;
        else if(arr[i]==1)
            one+=1;
        else if(arr[i]==2)
            two+=1;
    }

    
    while(zero!=0){
        arr[j] = 0;
        cout<<"arr["<<j<<"]"<<"="<<arr[j]<<" ";
        j+=1;
        zero -=1;
    }
    while(one!=0){
        arr[j] = 1;
        cout<<"arr["<<j<<"]"<<"="<<arr[j]<<" ";
        j+=1;
        one -=1;
    }
    while(two!=0){
        arr[j] = 2;
        cout<<"arr["<<j<<"]"<<"="<<arr[j]<<" ";
        j+=1;
        two -=1;
    }
    
}
/*
This is three pointer approach in which we have three pointer s , m and e in which we have s is on starting and m too and e at end.
then we compare arr[m] with each element till m < e and if m == 0 then m is we swap a[m] with a[s] and increase s and m +1 and if
m =1 then m is increase by m++; and if m == 2 then swap ( a[m], a[e]) and then e--
*/

void Sort_012_Algo2(int arr[], int n) // This is three pointer appraoch
{

    int s=0;
    int m= 0;
    int e = n-1;
    while(m<=e)
    {
        
        if(arr[m]==0)
        {
            swap(arr[s++],arr[m++]);
        }
        else if(arr[m]==1)
        {
            m++;
        }
        else{
            swap(arr[e--],arr[m]);
        }
    }



}

int main()
{
    cout<<"Enter size of array :";
    int size;
    cin>>size;
    int arr[100];
    cout<<"Enter elements of array"<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    // Sort_012_Algo1(arr,size);
    Sort_012_Algo2(arr,size);
    printArray(arr,size);
    return 0;
}
