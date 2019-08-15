#include<iostream>

using namespace std;

int main()
{
    long long int R,N,Case=1,i;

    while(cin>>R>>N&&R&&N)
    {
        if(N>=R)
        cout<<"Case "<<Case++<<": "<<0<<endl;
        else
        {
            for(i=1;i<=26;i++)
            {
                if((N*i)+N>=R)
                break;
            }
            if(i>26)
            cout<<"Case "<<Case++<<": "<<"impossible"<<endl;
            else
            cout<<"Case "<<Case++<<": "<<i<<endl;
        }
    }
    return 0;
}
