using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
        string str;

        while(cin>>str)
        {
                char c=getchar();
                int l=str.length();

                for(int i=l-1;i>=0;i--)
                {
                        cout<<str[i];
                }

                cout<<c;
        }

        return 0;
}
