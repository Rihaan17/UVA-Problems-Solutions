using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define n 10000000

int prime[n];

long long int arr[n],k,i,j;

void primeFIND()
{

    k=0;

    memset(prime , 0 , sizeof prime);

    prime[0]=prime[1]=1;

    for(i=2;i<=n;i++)
    {
        if(!prime[i])
        {
            for(j=i*i;j<=n;j=j+i)
                prime[j]=1;
            arr[k++]=i;
        }
    }

}

int main()
{
    long long int a,b,m,cnt,index,idiot;
    int flag;
    int newer[10000+10];
    double ans;
    primeFIND();

    memset(newer , 0 , sizeof newer);

    for(i=0;i<=10000;i++)
    {
        idiot=i*i+i+41;
        if(idiot<n)
        {
            if(!prime[idiot])
            newer[i]=1;
        }
        else
        {
            index=flag=1;
                while(arr[index]*arr[index]<=idiot)
                {
                    if(idiot % arr[index]==0){
                        flag=0;
                        break;
                    }
                    index++;
                }
                if(flag)
                newer[i]=1;
        }
    }
    while(cin>>a>>b)
    {
        cnt=0;

        for(m=a;m<=b;m++)
        {
            if(newer[m])
            cnt++;
        }

        ans=(double)((cnt*100.0)/(double)(b-a+1));
        printf("%.2lf\n",ans);

        //printf ("%.2lf\n", (cnt * 100.0) / (double)(b - a + 1) + 1e-9);


    }
    return 0;
}
