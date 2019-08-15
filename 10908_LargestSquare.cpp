#include<iostream>

using namespace std;

char vr[110][110];
int T,M,N,Q,x,y,x1,x2,y1,y2,i,cnt;
char c;

int TrueOrFalse()
{
    if(!(x1>=0&&x1<M)&&(x2>=0&&x2<M)&&(y1>=0&&y1<N)&&(y2>=0&&y2<N))
    return 0;

    for(i=y2;i<=y1;i++)
    {
        if(vr[x1][i]!=c||vr[x2][i]!=c)
        return 0;
    }
    for(i=x2;i<=x1;i++)
    {
        if(vr[i][y1]!=c||vr[i][y2]!=c)
        return 0;
    }

    return 1;
}

int main()
{
    cin>>T;

    while(T--)
    {
        cin>>M>>N>>Q;
        for(i=0;i<M;i++)
        {
            cin>>vr[i];
        }

        cout<<M<<" "<<N<<" "<<Q<<endl;
        while(Q--)
        {
            cnt=0;
            cin>>x>>y;
            if((x>=0&&x<M)&&(y>=0&&y<N))
            {
                cnt=1;
                c=vr[x][y];
            }
            x1=x+1;
            x2=x-1;
            y1=y+1;
            y2=y-1;
            while(TrueOrFalse())
            {
                    cnt++;
                    x1++;
                    y1++;
                    x2--;
                    y2--;
            }

            cout<<cnt*2-1<<endl;
        }
    }
    return 0;
}
