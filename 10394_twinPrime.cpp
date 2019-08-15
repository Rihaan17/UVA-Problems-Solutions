#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>

#define n 20000000

using namespace std;

int prime[n];

long long int k,i,j;

vector <long long int > vr;
vector<long long int > ans;

void primeFIND()
{
    vr.clear();
    memset(prime , 0 , sizeof prime);
    prime[0]=prime[1]=1;

    for(i=2;i<=n;i++)
    {
        if(!prime[i])
        {
            for(j=i*i;j<=n;j=j+i)
                prime[j]=1;
            vr.push_back(i);
        }
    }
}

int main()
{
    long long int S;
    primeFIND();

     for(i=1;i<vr.size();i++)
        if(vr[i]-vr[i-1]==2)
        ans.push_back(vr[i-1]);

    while(cin>>S)
    {
       cout<<"("<<ans[S-1]<<", "<<ans[S-1]+2<<")"<<endl;
    }
    return 0;
}
