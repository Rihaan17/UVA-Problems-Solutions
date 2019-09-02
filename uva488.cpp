#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int T,a,f,i,k,m;
    vector<char>vr[10000];

    cin>>T;
    cout<<endl;
    while(T--)
    {

        cin>>a>>f;
        for(i=1;i<=a;i++)
        {
                for(k=0;k<i;k++)
                vr[i-1].push_back(i+48);
        }
        k=i-1;
        for(i=k-1;i>0;i--)
        {
            for(m=0;m<i;m++)
            vr[k].push_back(i+48);
            k++;
        }

        while(f--)
        {
            for(i=0;i<(2*a)-1;i++)
            {
                for(k=0;k<vr[i].size();k++)
                {
                     cout<<vr[i][k];
                }
                  if(f==0)
                     vr[i].clear();

                cout<<endl;
            }
            if(T==0&&f==0)
            break;
            cout<<endl;
        }
       /* if(T!=0)
        cout<<endl;*/
    }
    return 0;
}
