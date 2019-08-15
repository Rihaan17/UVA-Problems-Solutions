#include<iostream>
#include<cmath>

using namespace std;

long long H(int n)
{
        long long res = 0;
        int i;

        for(i=1;i<=sqrt(n);i++)
        {
            res=res+((n/i-(n/(i+1)))*i);
        }

        for(i=1;n/i>sqrt(n);i++)
        {
            res=res+n/i;
        }

        return res;
}

int main()
{
    long long int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
         cout<<H(n)<<endl;
    }
    return 0;

}
