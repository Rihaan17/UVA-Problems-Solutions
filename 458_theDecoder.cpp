#include<stdio.h>

int main()
{
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='\n')
        printf("\n");
        else
        printf("%c",c-7);
    }
    return 0;
}
