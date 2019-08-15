#include<iostream>
#include<map>

using namespace std;


int main()
{
    long long int arr[110],N,i,j,Case=1,flag;
    map<int,int>m;

    while(cin>>N)
    {
        m.clear();
        flag=1;
        for(i=0;i<N;i++)
        {
            cin>>arr[i];
        }

        for(i=0;i<N-1;i++)
        {
            if(arr[i]<1||arr[i]>=arr[i+1])
            {
                flag=0;
                i=N;
            }
        }

        if(flag)
        {
            for(i=0;i<N;i++)
            {
                for(j=i;j<N;j++)
                {
                    if(m[arr[i]+arr[j]]==1)
                    {
                        flag=0;
                        i=j=N;
                    }
                    else
                    m[arr[i]+arr[j]]=1;
                }
            }
        }


        if(flag)
        cout<<"Case #"<<Case++<<": It is a B2-Sequence."<<endl<<endl;
        else
        cout<<"Case #"<<Case++<<": It is not a B2-Sequence."<<endl<<endl;
    }
    return 0;
}
