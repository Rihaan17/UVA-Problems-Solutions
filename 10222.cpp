#include<stdio.h>
#include<string.h>

int main()
{
    char c[100];
    gets(c);
    for(int i=0;i<strlen(c);i++)
    {
        if(c[i]!=' ')
        {
            printf("%c",c[i]-3);
            //printf("%d",c[i]-2);
        }
        else
        printf("%c",' ');
    }
    return 0;
}
