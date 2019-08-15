using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

struct info{

        int indx, freq;
}M[10000000];

int arr[100000+10];

void built_tree(int node, int u, int v)
{
        if(u==v)
        {
                M[node].indx=u;
                M[node].freq=1;
        }

        else
        {
                built_tree(node*2, u, (u+v)/2);
                built_tree(2*node+1,(u+v)/2+1,v);

                if(arr[M[node*2].indx]==arr[M[node*2+1].indx])
                {
                        M[node].indx=M[node*2].indx;
                        M[node].freq=M[node*2].freq+M[node*2+1].freq;
                }
                else if(M[node*2].freq>=M[node*2+1].freq)
                {
                        M[node].freq=M[node*2].freq;
                        M[node].indx=M[node*2].indx;
                }
                else
                {
                        M[node].freq=M[node*2+1].freq;
                        M[node].indx=M[node*2+1].indx;
                }
        }
}

int query(int node, int left, int right, int u, int v)
{
        if(left>v||right<u)
                return -1;

        if(left>=u&&right<=v)
                return M[node].freq;

        int p1 = query(node*2, left, (left+right)/2, u,v);
        int p2 = query(node*2+1, (left+right)/2+1, right, u, v);

        if(p1==-1)
                return p2;
        if(p2==-1)
                return p1;

        return (p1>p2)? p1:p2;
}

int main()
{
        int n,q,u,v,i;

        while(scanf("%d",&n)&&n)
        {
                scanf("%d",&q);

                for(i=0;i<n;i++)
                        scanf("%d",&arr[i]);

                built_tree(1,0,n-1);

                while(q--)
                {
                        scanf("%d%d",&u,&v);
                        printf("%d\n",query(1,0,n-1,u-1,v-1));
                }
        }

        return 0;
}





/*#include<iostream>

using namespace std;

int a[10001][10001];

int BS(int i,int j,int k)
{
    int low=0,high=k,mid;

    while(low<high)
    {
        mid=(low+high)/2;
        if(i>a[mid][0])
        {
           if(mid+1>k)
           {
               if(a[mid][0]<=j)
               return mid;
               else
               return -1;
           }

           if(a[mid+1][0]>i)
           {
               if(a[mid+1][0]<=j)
               return mid+1;
               else
               return -1;
           }
           else
           low=mid+1;
        }
        else if(i<a[mid][0])
        {
                if(mid-1<0)
                {
                    if(a[mid][0]<=j)
                    return mid;
                    else
                    return -1;
                }

                if(a[mid-1][0]<i)
                {
                    if(a[mid][0]<=j)
                    return mid;
                    else
                    return -1;
                }
                else
                high=mid-1;
        }
        else
        return mid;
    }
    return -1;
}

int main()
{
    int n,q,i,j,k,arr[10001],count,f,index,max;

    while(cin>>n&&n&&cin>>q)
    {
        f=-1;
        for(k=0;k<n;k++)
        {
            cin>>arr[k];
            if(k&&arr[k]==arr[k-1])
            {
                count++;
            }
            else
            {
                count=1;
                a[++f][0]=arr[k];
            }
            a[f][1]=count;
        }

        while(q--)
        {
            cin>>i>>j;

            index=BS(i,j,f);
           if(index==-1)
            max=0;
            else
            {
                max=a[index][1];
                for(k=index+1;a[k][0]<=j&&k<=f;k++)
                {
                    if(a[k][1]>max)
                    max=a[k][1];
                }
            }
            cout<<max<<endl;
        }
    }
    return 0;
}
*/
