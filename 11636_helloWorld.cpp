#include<iostream>

using namespace std;

int main()
{
    long long int x,Case=1,i,count;

    while(cin>>x&&x>-1)
    {
        if(x==0)
        {
            cout<<"Case "<<Case++<<": "<<0<<endl;
            continue;
        }
        count=0;
        i=1;
        while(i<x)
        {
            i=i+i;
            count++;
        }
        cout<<"Case "<<Case++<<": "<<count<<endl;
    }
    return 0;
}
