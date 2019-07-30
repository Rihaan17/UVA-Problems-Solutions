#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int arr[100],n,i,sum,height,res,set=1;

    while(cin>>n&&n)
    {
        res=sum=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            sum=sum+arr[i];
        }

        height=sum/n;
        sort(arr,arr+n);
        for(i=0;i<n;i++)
        {
            if(arr[i]>height)
            break;
            res=res+(height-arr[i]);
        }

        cout<<"Set #"<<set++<<endl;
        cout<<"The minimum number of moves is "<<res<<"."<<endl<<endl;
    }
    return 0;
}
