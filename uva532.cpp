using namespace std;

#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>

#define di cout<<"enter"<<endl;

struct info
{
    int x,y,l,cost;
};



int dx[]={1,0,-1,0,0,0};
int dy[]={0,1,0,-1,0,0};
int dl[]={0,0,0,0,1,-1};

int level,row,col,taken[32][32][32];
char place[32][32][32];

bool valid(int x,int y,int l)
{
    if(x>=0&&x<row&&y>=0&&y<col&&l>=0&&l<level&&place[l][x][y]!='#'&&taken[l][x][y]==false)
        return true;
    return false;
}


int main()
{
    int i,j,k,sx,sy,sl,desx,desy,desl;

    while(scanf("%d%d%d",&level,&row,&col))
    {
        if(level==0&&row==0&&col==0)
            break;

        for(i=0;i<level;i++)
        {
            for(j=0;j<row;j++)
                scanf("%s",place[i][j]);
        }

        info start,recent;

        for(i=0;i<level;i++)
        {
            for(j=0;j<row;j++)
            {
                for(k=0;k<col;k++)
                {
                    if(place[i][j][k]=='S')
                    {
                        sl=i;sx=j;sy=k;
                    }

                    else if(place[i][j][k]=='E')
                    {
                        desl=i;desx=j;desy=k;
                    }

                    taken[i][j][k]=false;
                }
            }
        }

        start.l=sl;
        start.x=sx;
        start.y=sy;
        start.cost=0;

       // cout<<desl<<" "<<desx<<" "<<desy<<" done" <<endl;

        queue<info>Q;
        Q.empty();

        Q.push(start);

        int flag=1;

        while(!Q.empty()&&flag)
        {
            recent=Q.front();
            Q.pop();

            for(i=0;i<6;i++)
            {
                int r1=recent.x+dx[i];
                int r2=recent.y+dy[i];
                int r3=recent.l+dl[i];

                if(valid(r1,r2,r3))
                {
                    //cout<<r3<<" "<<r1<<" "<<r2<<" done" <<endl;

                    //di;
                    start.x=r1;
                    start.y=r2;
                    start.l=r3;
                    start.cost=1+recent.cost;
                    taken[r3][r1][r2]=true;

                    if(desx==r1&&desy==r2&&desl==r3)
                    {
                        //di;
                        flag=0;
                        break;
                    }
                    Q.push(start);
                }
            }

        }

        if(flag)
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n",start.cost);
        }
    }

    return 0;
}
