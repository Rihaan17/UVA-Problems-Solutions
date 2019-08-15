#include<iostream>

using namespace std;

int main()
{
    long long int a;

    while(cin>>a&&(a>=0))
    {
        if(a==1)
        cout<<"0%"<<endl;
        else
        cout<<a*25<<"%"<<endl;
    }
    return 0;
}
