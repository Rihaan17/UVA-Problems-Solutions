#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int T,a[5],Case=1;
    cin>>T;
    while(T--)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        cout<<"Case "<<Case++<<": "<<a[1]<<endl;
    }
    return 0;
}
