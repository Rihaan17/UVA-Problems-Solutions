#include<iostream>
#include<cstring>

using namespace std;

int cheak(char c)
{
    if(c>='A'&&c<='C')
    return 2;
    else if(c>='D'&&c<='F')
    return 3;
    else if(c>='G'&&c<='I')
    return 4;
    else if(c>='J'&&c<='L')
    return 5;
    else if(c>='M'&&c<='O')
    return 6;
    else if(c>='P'&&c<='S')
    return 7;
    else if(c>='T'&&c<='V')
    return 8;
    else
    return 9;
}

int main()
{
    string str;
    int i;
    while(getline(cin,str))
    {
        for(i=0;i<str.length();i++)
        {
            if(isupper(str[i]))
            cout<<cheak(str[i]);
            else
            cout<<str[i];
        }
        cout<<endl;
    }
    return 0;
}
