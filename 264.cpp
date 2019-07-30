#include<stdio.h>

int main()
{
    long long int p,q,n;
    while(scanf("%lld",&n)!=EOF)
    {
        p=1;
        q=1;
        printf("TERM %lld IS ",n);
        while(1)
        {
            if(p==1)
            {
                    n--;
                    if(n==0)
                    break;
                    q++;
                    n--;
                    while((q!=1)&&(n!=0))
                    {
                        p++;
                        q--;
                        if(q!=1)
                        n--;
                    }

            }
            else if(q==1)
            {
                n--;
                if(n==0)
                break;
                p++;
                n--;
                 if(n==0)
                    break;
                while((p!=1)&&(n!=0))
                {
                    p--;
                    q++;
                    if(p!=1)
                    n--;
                }
            }
             if(n==0)
              break;
        }
        printf("%lld/%lld\n",p,q);
    }
    return 0;
}
