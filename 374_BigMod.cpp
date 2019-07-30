using namespace std;

#include<iostream>

long long int a;

long long int BigMod(long long int b, long long int p,long long int m)
{

	if( p==0 )return 1;
	else if( p%2==0 )
	{
		a = BigMod(b, p/2, m);
		return (a*a)%m;
	}
	else
	{
	    a = BigMod(b, p-1, m);
        return (a*(b%m))%m;
	}

}


int main()
{
    long long int B,P,M;

    while(cin>>B>>P>>M)
    {
        cout<<BigMod(B,P,M)<<endl;
    }
    return 0;
}
