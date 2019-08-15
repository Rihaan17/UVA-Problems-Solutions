#include<stdio.h>

int main()
{
    float sum,avg,N;
    int count,arr[1050],R,i;
    scanf("%d",&count);
    while(count--)
    {
        sum=0;
        R=0;
        scanf("%f",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        avg=sum/N;
        for(i=0;i<N;i++)
        {
            if(arr[i]>avg)
            R++;
        }
        avg=(float)R/N;
        printf("%.3f%%\n",avg*100);
    }
    return 0;
}
