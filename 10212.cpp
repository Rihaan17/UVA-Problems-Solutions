using namespace std;

#include<iostream>

long long int calc(long long int u,long long int l)
{

    long long int i,pro=1;
    for(i=u;i>=l+1;i--)
    {
        pro=pro*i;
        while(pro%10==0)
            pro=pro/10;
        pro=pro%1000000000;
    }
    return pro%10;
}

int main()
{
    long long int a,b;

    while(cin>>a>>b)
    {
        if(b==0)
            cout<<1<<endl;
        else
            cout<<calc(a,a-b)<<endl;
    }
    return 0;
}


















/*#include <stdio.h>
#define P 20000000

typedef unsigned long long U;

U D[P+1000];
char a[P+1000];
char x[10][10];

void set()
{
    x[1][1]=1;
    x[1][3]=7;
    x[1][7]=3;
    x[1][9]=9;

    x[3][1]=3;
    x[3][3]=1;
    x[3][7]=9;
    x[3][9]=7;

    x[7][1]=7;
    x[7][3]=9;
    x[7][7]=1;
    x[7][9]=3;

    x[9][1]=9;
    x[9][3]=3;
    x[9][7]=7;
    x[9][9]=1;
}

void R ()
{
    U i,r;
    long long count;

    a[1]=1;
    D[1]=0;

    for(i=2; i<P+10; i++)
    {
        r=i;

        count=0;

        while(r%2==0)
        {
            r/=2;
            count++;
        }

        while(r%5==0)
        {
            r/=5;
            count--;
        }

        r%=10;
        a[i] = (r*a[i-1])%10;
        D[i] = D[i-1]+count;
    }
}

U X(U n, U r)
{
    U rem, dig, b[]={2,4,8,6};

    if(n==0)
        n=1;

    if(r==0)
        r=1;

    rem = D[n]-D[r];
    dig = x[a[n]][a[r]];

    rem%=4;
    if(rem==0)
        rem =4;
    rem=b[rem-1];

    dig*=rem;

    return dig%10;
}

int main()
{
    U n,r;

    R();
    set();

    while(scanf("%llu %llu",&n,&r)==2)
    {
        printf("%llu\n",X(n,n-r));
    }

    return 0;
}*/
