using namespace std;

#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<cstring>
#include<map>

#define di cout<<"enter"<<endl

map<string,long>m;

void bfs()
{
    string temp;
    queue<string>Q;

    for(char i='a';i<='z';i++)
    {
        string Eemp;
        Eemp.push_back(i);
        Q.push(Eemp);
    }

    long cnt=1;

    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        m[temp]=cnt;
        cnt++;

        if(temp=="vwxyz")
            return;

        for(char i=temp[temp.length()-1]+1;i<='z';i++)
        {
            string recent=temp+i;
            Q.push(recent);
        }
    }
}

bool valid(string str)
{
    int l=str.length();

    for(int i=0;i<l-1;i++)
    {
        if(str[i]>=str[i+1])
            return false;
    }
    return true;
}

int main()
{
    string str;
    bfs();

    while(cin>>str)
    {
        if(valid(str))
        {
            printf("%ld\n",m[str]);
        }
        else
        {
            printf("0\n");
        }
    }

    return 0;
}
