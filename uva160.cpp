using namespace std;

#include<iostream>
#include<cstdio>



int main()
{
        int ans[30],n,N,temp,i,j,count;
        int prime [] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

        while(scanf("%d",&N)&&N)
        {
                for(i=0;i<25;i++)
                        ans[i]=0;
                n=N;
                while(n>1)
                {
                        i=0;
                        temp=n;
                        while(temp>1)
                        {
                                count=0;
                                while(temp%prime[i]==0)
                                {
                                        count++;
                                        temp/=prime[i];
                                }
                                ans[i]+=count;
                                i++;
                        }
                        n--;
                }

                for(i=24;i>=0;i--)
                {
                        if(ans[i]>0)
                                break;
                }

                printf("%3d! =",N);
                //printf("%6c",' ');

                for(j=0;j<=i;j++)
                {
                       if(j==15)
                                printf("\n%6c",' ');
                       printf("%3d", ans[j]);

                }

                printf("\n");

        }

        return 0;
}
