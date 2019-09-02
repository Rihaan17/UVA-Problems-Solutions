using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>

int main()
{
    char str[210];
    int count[200],i;

    while(gets(str))
    {
        for(i=63;i<130;i++)
            count[i]=0;
        int l=strlen(str),maX=0;

        for(i=0;i<l;i++)
        {
            if(!isalpha(str[i]))
                continue;
            count[str[i]]++;
            if(count[str[i]]>maX)
                maX=count[str[i]];
        }

        for(i=65;i<124;i++)
        {
            if(count[i]==maX)
                printf("%c",i);
        }

        cout<<" "<<maX<<endl;
    }

    return 0;
}

