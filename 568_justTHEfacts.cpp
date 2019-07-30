using namespace std;

#include<iostream>


int arr[10010];

void calc()
{
   int pro,i;
   arr[0]=arr[1]=pro=1;
    for(i=2;i<=10001;i++)
    {
        pro=pro*i;
        while(pro%10==0)
            pro=pro/10;
        pro=pro%100000;
        arr[i]=pro%10;
    }

}

int main()
{
    int n;
    calc();

    while(cin>>n)
    {
        cout.width(5);
        cout<<n<<" -> "<<arr[n]<<endl;
    }
    return 0;
}


 /*  temp3=x;
        temp2=x%10;
        while(temp2==0)
        {
            x=x/10;
            temp2=x%10;
        }


        temp=(arr[temp3-1]*temp2);
        pro=temp%10;

        while(pro==0)
        {
            temp=temp/10;
            pro=temp%10;
        }

        return pro;
//
    //}
   /* for(k=x;k>1;k--)
    {
        temp=k%10;
        while(temp==0)
        {
            k=k/10;
            temp=k%10;
        }

        pro=pro*temp;
        temp2=pro%10;

        while(temp2==0)
        {
            pro=pro/10;
            temp2=pro%10;
        }
        pro=temp2;

    }
    return pro;*/
