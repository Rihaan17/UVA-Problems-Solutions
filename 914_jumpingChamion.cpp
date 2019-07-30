using namespace std;

#include<iostream>
#include<cstring>
#include<algorithm>

#define n 1000010

int primelist[n];
long long int k,i,j,arr[n];

void primeFIND()
{
    k=0;
    memset(primelist,0,sizeof(primelist));

    primelist[0]=primelist[1]=1;



    for(i=2; i<n ; i++)
    {
        if(!primelist[i])
        {
            for (int j = 2; i * j < n; j++)
                {
                    primelist[i * j] = 1;
                }
            arr[k++]=i;
        }
    }


}

long long int BS(long long int x)
{
    long long int low=0,high=k-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]>x)
            high=mid-1;
        else if(arr[mid]<x)
            low=mid+1;
        else
            return mid;
    }
    return 0;
}

int main()
{
    long long int T,l,h,m,index1,index2,result[1000],temp[100000],max,Findex,temp2,salt;
    primeFIND();
    cin>>T;

    while(T--)
    {
        m=0;
        cin>>l>>h;
        while(primelist[l])
            l++;
        while(primelist[h])
            h--;
        index1=BS(l);
        index2=BS(h);

        //cout<<index1<<" "<<index2<<endl;

        if(index2-index1<1)
            cout<<"No jumping champion"<<endl;
        else
        {
            for(i=index1+1;i<=index2;i++)
            {
                temp[m++]=arr[i]-arr[i-1];
                //cout<<temp[m-1]<<" ";
            }

            sort(temp,temp+m);
            salt = m;
            memset(result,0,sizeof result);
            m=0;


            for(i=temp[0];m<salt;i=temp[m])
            {
                result[i]++;
                m++;
            }

            max = result[0];
            Findex = 0;

            for(i=1;i<=temp[salt-1];i++)
            {
                if(max<result[i])
                {
                    max = result[i];
                    Findex = i;
                }

                else if(max == result[i])
                    temp2 = result[i];
                   // cout<<result[i]<<" ";
            }

            if(temp2==max)
                cout<<"No jumping champion"<<endl;
            else
                cout<<"The jumping champion is "<<Findex<<endl;

        }

    }

    return 0;
}
