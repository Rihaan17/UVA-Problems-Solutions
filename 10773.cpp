#include<stdio.h>
#include<math.h>

int main()
{
    int x,i=1;
    double d,v,u;
    scanf("%d",&x);
    while(x--)
    {
        scanf("%lf %lf %lf",&d,&v,&u);
        if(v==0 || u == 0 || v >=u)
            printf("Case %d: can't determine\n",i++);
        else
        {
             printf("Case %d: %0.3lf\n",i++,((d/(sqrt(u*u-v*v)))-(d/u)));

        }
    }
    return 0;
}
