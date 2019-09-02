using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
        unsigned long long int n,k,ans,i;

        while(scanf("%llu%lld",&n,&k)==2)
        {
                if(n==0&&k==0) break;

                if(k>n/2) k=n-k;

                ans=1;
                for(i=0;i<k;i++)
                {
                        ans*=(n-i);
                        ans/=(i+1);
                }

                printf("%llu\n",ans);
        }

        return 0;
}
