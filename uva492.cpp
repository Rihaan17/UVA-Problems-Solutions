using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>

bool vowel(char c)
{
    if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
        return true;
    return false;
}

int main()
{
    char c,ch;


    while(scanf("%c",&c)==1)
    {
        if(isalpha(c))
        {
            if(vowel(c))
            {
                while(isalpha(c))
                {
                    printf("%c",c);
                    scanf("%c",&c);
                }
                printf("ay");
            }
            else
            {
                ch=c;
                c=getchar();
                while(isalpha(c))
                {
                    printf("%c",c);
                    scanf("%c",&c);
                }
                printf("%cay",ch);
            }
        }

        printf("%c",c);
    }

    return 0;
}


/* while(gets(str))
    {
        int l=strlen(str);
        int i=0,flag=0;
        while(i<l)
        {
            if(vowel(str[i]))
            {
                while(i<l&&str[i]!=' ')
                {
                    if(str[i]=='.')
                    {
                        flag=1;
                    }
                    else
                        cout<<str[i];
                    i++;
                }
                cout<<"ay";//<<str[i];
                if(i<l)
                    cout<<" ";
                i++;
            }
            else
            {
                c=str[i];
                i++;
                while(i<l&&str[i]!=' ')
                {
                    if(str[i]=='.')
                    {
                        flag=1;
                    }
                    else
                        cout<<str[i];
                    i++;
                }
                cout<<c<<"ay";//<<str[i];
                 if(i<l)
                    cout<<" ";
                i++;
            }
        }
        if(flag)
            cout<<".";

        cout<<endl;*/
