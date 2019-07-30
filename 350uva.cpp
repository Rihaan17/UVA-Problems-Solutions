#include<iostream>
using namespace std;

int main()
{
    unsigned long long int Z,I,L,M,temp,count,i=1;

    while((cin>>Z>>I>>M>>L)&&(Z && L && I && M))
    {
        count=0;
        temp=((Z*L+I)%M);
        L=temp;
        while(1)
        {
            L=((Z*L+I)%M);
            if(temp==L)
            break;
            count++;
        }
        cout<<"Case "<<i++<<": "<<++count<<endl;
    }
    return 0;
}

/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
#define LLU long long unsigned int
#define LLD long long double
int main()
{
    LLU Z,I,M,L,N,count,cases=0;
    while(cin>>Z>>I>>M>>L)
    {
        if(!Z && !L && !I && !M)
        break;
        bool done[1000000]={false};
        count=0;
        while(1)
        {
            N=((Z*L+I)%M);
            L=N;
            if(done[L]) break;
            done[L]=true;
            count++;
        }
        cout<<"Case" <<++cases<<":"<<count<<endl;
    }
    return 0;
}*/
