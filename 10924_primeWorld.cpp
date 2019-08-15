#include<iostream>
#include<map>
#include<cstring>
#include<cmath>

using namespace std;


int FIND(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(!(n%i))
        return 0;
    }
    return 1;
}

int main()
{
    string str;
    int i,sum;
    map<char, int>world;

    for(i=0;i<26;i++)
    world.insert(pair<char, int>('a'+i,i+1));

    for(i=0;i<26;i++)
    world.insert(pair<char, int>('A'+i,i+27));

    while(cin>>str)
    {
        sum=0;
        for(i=0;i<str.length();i++)
        {
            sum=sum+world.find(str[i])->second;
        }
        if(FIND(sum))
        cout<<"It is a prime word."<<endl;
        else
         cout<<"It is not a prime word."<<endl;
    }
    return 0;
}

