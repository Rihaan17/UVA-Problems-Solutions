/*
        Author: Golam Rahman Tushar
        ........Aust Cse 27th batch.........
*/

//{ Template

//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;
//}

//}
//{ Floating-points
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}

#define INF 1<<29
#define ll long long

template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
//}

template <class T> T gcd(T a,T b){if(b==0) return a;else return gcd(b,a%b);}
template <class T> T lcm(T a,T b){return (a*b)/gcd(a,b);}
template <class T> T power( T a, T b){if(b==0) return 1; T x=a;for(T i=2;i<=b;i++) a=a*x;return a;}
template <class T> T BigMod(T a,T b,T c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){T x=BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*BigMod(a,b-1,c)%c)%c;}
template <class T> T squ(T a) { return a*a; }

struct info {
        int x, y;
}graph[10];

struct edge {
        int u, v; double w;
        bool operator < (const edge& c) const
        {
                return w<c.w;
        }
};

vector<edge>v, ans;

int pre[10];

int find(int x)
{
        return (pre[x]==x ? x: find(pre[x]));
}
int n, mp[157][157], track[10];
double cost;

vector<int>FINAL[10];

void mst()
{
        int sz = v.size(), cnt = 0, i;
        sort(v.begin(), v.end());

       // for(i=0;i<sz;i++) cout<<v[i].u<<"    "<<v[i].v<<"    "<<v[i].w<<endl;
        for(i=0;i<n;i++) { pre[i] = i; track[i] = 0; }

        for(i=0;cnt<n-1&&i<sz;i++)
        {
                int u = find(v[i].u);
                int vv = find(v[i].v);

                if(u!=vv&&track[v[i].u]<2&&track[v[i].v]<2)
                {
                        FINAL[v[i].u].push_back(v[i].v);
                        FINAL[v[i].v].push_back(v[i].u);
                        pre[u] = vv; track[v[i].u]++; track[v[i].v]++;
                        cost+=v[i].w;
                        ans.push_back(v[i]);
                        cnt++;
                }
        }
        //cout<<"i : "<<i<<endl;
}

int main ()
{
        int i, j, Case = 1; double wt[10][10];
        while(scanf("%d",&n)==1&&n)
        {
                int cnt = 0;
                for(i=0;i<n;i++)
                {
                        scanf("%d %d",&graph[i].x, &graph[i].y);
                        mp[graph[i].x][graph[i].y] = i;
                        mp[graph[i].y][graph[i].x] = i;

                        for(j=0;j<i;j++)
                        {
                                edge ed;
                                ed.u = mp[graph[j].x][graph[j].y];
                                ed.v = mp[graph[i].x][graph[i].y];
                                ed.w = sqrt(squ(graph[i].x-graph[j].x)+squ(graph[i].y-graph[j].y));
                                wt[ed.u][ed.v] = wt[ed.v][ed.u] = ed.w;
                                /*cout<<graph[i].x<<"   "<<graph[i].y<<"   "<<graph[j].x<<"   "<<graph[j].y<<endl;
                                cout<<"  w :: "<<ed.w<<endl;*/
                                //cout<<ed.u<<"     "<<ed.v<<"     "<<ed.w<<endl;
                                v.push_back(ed);
                        }
                }

                cost = 0.0;
                mst();

                int source;
                for(i=0;i<n;i++) if(track[i]==1&&FINAL[i].size()==1) { source = i; break; }

                printf("**********************************************************\n");
                printf("Network #%d\n",Case++);
                int visited[10] = {0};

                int x1, x2, y1, y2, des;
                for(i=0;i<n-1;i++)
                {
                        visited[source] = 1;
                        if(visited[FINAL[source][0]]==0) {
                                des = FINAL[source][0];
                                visited[des] = 1;
                        }
                        else {
                                des = FINAL[source][1];
                                visited[des] = 1;
                        }
                        x1 = graph[source].x; y1 = graph[source].y; x2 = graph[des].x; y2 = graph[des].y;
                        //cout<<"source "<<source<<"   destination   "<<des<<endl;
                        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x1, y1, x2, y2, wt[source][des]+16);
                        if(i+1<n-1) source = des;
                }

                printf("Number of feet of cable required is %.2lf.\n",cost+(n-1)*16);

                for(i=0;i<n;i++) FINAL[i].clear();
                v.clear(); ans.clear();
        }
        return 0;
}

