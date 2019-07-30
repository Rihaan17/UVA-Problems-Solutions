#include<iostream>
#include<cstring>

using namespace std;

long long int arr[1010];

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
    long long int n;

    while(cin>>n&&n)
    {
        memset(arr , -1 ,sizeof arr);
        cout<<fibonacci(n)<<endl;
    }
    return 0;
}
