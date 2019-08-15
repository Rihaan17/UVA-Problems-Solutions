using namespace std;

#include<iostream>
#include<cmath>
#include<cstring>


/*long long int power(long long int i,long long int cnt)
{
    long long int product = i,k;
    for ( k = 2; k <= cnt; k++ )
    {
        product *= i;
    }

    return product;
}*/

int main()
{
    long long int n,i,cnt,m,temp;

    while(cin>>n&&n)
    {
        int flag=1;
        if(n<0)
        {
            temp=sqrt((-n));
            for(i=-2;i>=-temp;i--)
            {
                m=i;
                cnt=2;
                while(m>n)
                {
                    m=power(i,cnt);
                    cnt++;
                }
                if(m==n)
                {
                    cout<<cnt-1<<endl;
                    flag=0;
                    break;
                }
            }
        }
        else
        {
            temp=sqrt(n);
            for(i=2;i<=sqrt(n);i++)
            {
                m=i;
                cnt=2;
                while(m<n)
                {
                    m=power(i,cnt);
                    cnt++;
                }
                if(m==n)
                {
                    cout<<cnt-1<<endl;
                    flag=0;
                    break;
                }
            }
        }


        if(flag)
            cout<<1<<endl;

    }

    return 0;
}
