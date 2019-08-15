#include<iostream>
#include<cstring>

using namespace std;

#define max(a,b)  a>b?a:b

void swap(int *m,int *n)
{
    int temp;
    temp=*m;
    *m=*n;
    *n=temp;
}
int main()
{
    int m,n,t,i,arr[10030];

    while(cin>>m>>n>>t)
    {
        if(m>n)
        swap(m,n);
        memset(arr,0,sizeof arr);
        arr[m]=arr[n]=1;
        for(i=m;i<=t;i++)
        {
            if(arr[i])
            {
                arr[i+m]=max(arr[i+m],arr[i]+1);
                arr[i+n]=max(arr[i+n],arr[i]+1);
            }
            if(i+m>t)
            break;
        }
        if(arr[t])
        cout<<arr[t]<<endl;
        else
        {
            i=t-1;
            while(arr[i]==0&&i>0)
            i--;
            cout<<arr[i]<<" "<<t-i<<endl;
        }
    }
    return 0;
}
/*Critical Input :

852 965 9999
96 52 50
48 52 55
6 9 96
3 5 2
3 5 4
Critical output :

11 62
0 50
1 3
16
0 2
1 1
*/
