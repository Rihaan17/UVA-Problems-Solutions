#include<iostream>

using namespace std;

int main()
{
    long long int count,a,b,c,n=1;
    cin>>count;

    while(count--)
    {
        cin>>a>>b>>c;
        if((a+b<=c||a+c<=b||b+c<=a))
        cout<<"Case "<<n++<<": "<<"Invalid"<<endl;
        else
        {
            if(a==b==c)
            cout<<"Case "<<n++<<": "<<"Equilateral"<<endl;
            else if(a==b||a==c||b==c)
            cout<<"Case "<<n++<<": "<<"Isosceles"<<endl;
            else
            cout<<"Case "<<n++<<": "<<"Scalene"<<endl;
        }
    }
    return 0;
}
