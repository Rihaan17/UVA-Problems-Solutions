using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
    char str[101][101];
    int i,l,maX,j,k;

    memset(str,' ',sizeof(str));

    maX=i=0;

    while(gets(str[i]))
    {
        l=strlen(str[i]);
        if(l>maX)
        {
            maX=l;
        }
        else
            str[i][l]=' ';

        i++;
    }

    for(j=0;j<maX;j++)
    {
        for(k=i-1;k>=0;k--)
        {
            printf("%c",str[k][j]);
        }
        printf("\n");
    }

    return 0;
}
