#include<iostream>
#include<cstring>
using namespace std;
long long int arr[10050][10050];

int main()
{
    long long int n,i,j,sum1,sum2,flag;

    while(cin>>n&&n)
    {
        memset(arr,0,sizeof arr);
        flag=n-1;
        sum1=sum2=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>arr[i][j];
                if(i==j)
                sum1=sum1+arr[i][j];
            }
            sum2=sum2+arr[i][flag];
            flag--;
        }
        if(sum1==sum2)
        cout<<"homogeneous"<<endl;
        else
        cout<<"not homogeneous"<<endl;
    }
    return 0;
}
