#include<stdio.h>
#include<string.h>

int main()
{
    char word[500],i,count,l,flag;
    while(gets(word))
    {
        count=0;
        l=strlen(word);
        flag=1;
        for(i=0;i<l;i++)
        {
             if((((word[i]>='a')&&(word[i]<='z'))||((word[i]>='A')&&(word[i]<='Z')))&&flag)
            {
                count++;
                flag=0;
            }
            else if(!(((word[i]>='a')&&(word[i]<='z'))||((word[i]>='A')&&(word[i]<='Z'))))
            {
                flag=1;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
