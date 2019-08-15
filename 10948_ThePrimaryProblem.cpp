using namespace std;

#include<iostream>
#include<cstring>
#include<cmath>

#define n 1000010


long long int c,j,k,arr[1050];
int prime[n];

void primeFIND()
{
    k=0;
    memset(prime , 0 , sizeof prime);
    prime[0]=prime[1]=1;

    for(c=2; c<=sqrt(n) ; c++)
    {
        if(!prime[c])
        {
            for(j=c*c; j<=n ;j=j+c)
            {
                prime[j]=1;
            }
            arr[k++]=c;
        }
    }
}

int main()
{
    long long int N,temp,flag,l;
    primeFIND();

    while(cin>>N&&N)
    {
        temp=2;
        l=1;
        flag=1;
        while(N-temp>=temp)
        {
            if(!prime[temp]&&!prime[N-temp])
            {
              flag=0;
              break;
            }
            temp=arr[l++];
        }

        cout<<N<<":"<<endl;

        if(flag)
        cout<<"NO WAY!"<<endl;
        else
        {
            if(temp<N-temp)
                cout<<temp<<"+"<<N-temp<<endl;
            else
                cout<<N-temp<<"+"<<temp<<endl;
        }
    }
    return 0;
}
