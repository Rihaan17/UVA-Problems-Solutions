using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

typedef unsigned long long int ll_d;

ll_d dp[30000+10][12],N;
int coin[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
bool visited[30000+10][12];

ll_d solve(ll_d value,ll_d i)
{
    if(i>=11||value<=0)
    {
        if(value==0)
            return 1;
        return 0;
    }

    if(visited[value][i])
        return dp[value][i];

    ll_d ans=0,k;

    for(k=0;k*coin[i]<=value;k++)
        ans+=solve(value-k*coin[i],i+1);

    visited[value][i]=true;

    return dp[value][i]=ans;
}

int main()
{
        ll_d m,n;
        ll_d ansi[30000+10],i;
        memset(visited,false,sizeof(visited));

        for(i=0;i<=30005;i++)
                ansi[i]=solve(i,0);

        while(scanf("%llu.%llu",&m,&n) && (m||n))
        {
                /*if(n==0.00)
                        break;*/
                N=(int)(m*100+n);

                printf("%3llu.%.2llu%17llu\n",m,n,ansi[N]);

        }

        return 0;
}

  /* int ans=ansi[N];//solve(N,0);
                int temp=ans,cnt=0;

                while(temp)
                {
                        temp/=10;
                        cnt++;
                }

                for(i=0;i<17-cnt;i++)
                        cout<<" ";

                printf("%d\n",ans);*/


