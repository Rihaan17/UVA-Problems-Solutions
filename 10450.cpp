#include<iostream>
#include<cstring>

using namespace std;

long long int arr[110];

long long int fibonacci(long long int n)
{
    if(arr[n]!=-1)
    return arr[n];
    if(n==0||n==1)
    return 1;
    else
    return arr[n]=fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    long long int n,T,CASE=1;
    memset(arr , -1 ,sizeof arr);
    cin>>T;

    while(T--)
    {
        cin>>n;
        cout<<"Scenario #"<<CASE++<<":"<<endl<<fibonacci(n+1)<<endl;
        cout<<endl;
    }
    return 0;
}

