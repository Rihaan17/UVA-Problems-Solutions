#include<stdio.h>
#include<string.h>

int main()
{
    char s1[10]="too long",s2[10]="too low",s3[10]="right on",s[10];
    int n;
    while(scanf("%d",&n)&&n)
    {
        while(1)
        {
            gets(s);
            getchar();
            scanf("%d",&n);
            if(!strcmp(s,s3))
            break;
        }

    }
}
