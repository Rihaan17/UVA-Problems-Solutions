#include<iostream>

using namespace std;

int main()
{
    int T,a,f,i,m,k;
    cin>>T;

    while(T--)
    {
        cin>>a>>f;
        while(f--)
        {
             for(i=1;i<=a;i++)
            {
                for(k=0;k<i;k++)
                {
                    cout<<i;
                }
                cout<<endl;
            }
            k=i-1;
            for(i=k-1;i>0;i--)
            {
                    for(m=0;m<i;m++)
                    cout<<i;
                    cout<<endl;
            }
            if(T==0&&f==0)
            break;
            cout<<endl;
        }
    }
    return 0;
}



/*while(T--)
    {
        cin>>a>>f;
        for(i=1;i<=a;i++)
        {
            for(k=0;k<i;k++)
            {
                arr[i-1][k]=i+48;
            }
        }
        k=i-1;
        for(i=k-1;i>0;i--)
        {
            for(m=0;m<i;m++)
            arr[k][m]=i+48;
            k++;
        }

        while(f--)
        {
            for(i=0;i<(2*a)-1;i++)
            {
                cout<<arr[i];
                cout<<endl;
            }
            cout<<endl;
        }
        if(T-1>0)
        cout<<endl;
*/
