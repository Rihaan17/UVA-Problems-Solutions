#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int  MAX(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int T,count,count1,count2,count3,i,k,a[5][10030],arr[5][10030],cnt[10],Case=1,temp,max;
    cin>>T;

    while(T--)
    {
        count1=count2=count3=0;
        memset(arr,0,sizeof arr);
        for(i=1;i<=3;i++)
        {
            cin>>count;
            for(k=1;k<=count;k++)
            {
                cin>>temp;
                if(temp>0&&temp<=10000)
                {
                     a[i][k]=temp;
                    arr[i][a[i][k]]=1;
                }
                else
                count--;
            }
            cnt[i]=count;
            sort(a[i],a[i]+count+1);
        }

        for(i=1;i<=cnt[1];i++)
        {
            if(!(arr[2][a[1][i]]||arr[3][a[1][i]]))
            count1++;
        }

        for(i=1;i<=cnt[2];i++)
        {
            if(!(arr[1][a[2][i]]||arr[3][a[2][i]]))
            count2++;
        }

        for(i=1;i<=cnt[3];i++)
        {
            if(!(arr[2][a[3][i]]||arr[1][a[3][i]]))
            count3++;
        }

        cout<<"Case #"<<Case++<<":"<<endl;//Case #1:
        max=MAX(count1,MAX(count2,count3));

        if(max==count1)
        {
            cout<<1<<" "<<count1<<" ";//1
            for(i=1;i<=cnt[1];i++)
            {
                if(!(arr[2][a[1][i]]||arr[3][a[1][i]]))
                cout<<a[1][i];
                if(i+1>cnt[1])
                cout<<endl;
                else
                cout<<" ";
           }
        }
        if(max==count2)
        {
             cout<<2<<" "<<count2<<" ";//2
            for(i=1;i<=cnt[2];i++)
            {
                if(!(arr[1][a[2][i]]||arr[3][a[2][i]]))
                cout<<a[2][i];
                if(i+1>cnt[2])
                cout<<endl;
                else
                cout<<" ";
            }
        }
        if(max==count3)
        {
            cout<<3<<" "<<count3<<" ";//3
            for(i=1;i<=cnt[3];i++)
            {
                if(!(arr[2][a[3][i]]||arr[1][a[3][i]]))
                cout<<a[3][i];
                if(i+1>cnt[3])
                cout<<endl;
                else
                cout<<" ";
            }
        }
    }

    return 0;
}
