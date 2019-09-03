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
#define eps 10e-7

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

int dp[800], ans[800];
bool vis[800];

int main ()
{
    freopen("input.txt","r",stdin);
    int coin[7] = {5,10,20,50,100,200}, i, j, no[7], k;

    for(i=0;i<800;i+=5) dp[i] = 9999;
    dp[0] = 0;

    for(i=5;i<800;i+=5) {
        for(j=0;j<6;j++) {
            if(i>=coin[j]&&(dp[i-coin[j]]+1)<dp[i])
                dp[i] = dp[i-coin[j]]+1;
        }
    }

    //for(i=5;i<=100;i+=5) cout<<dp[i]<<endl;

    while(scanf("%d %d %d %d %d %d",&no[0],&no[1],&no[2],&no[3],&no[4],&no[5])==6) {
        if(no[0]==0&&no[1]==0&&no[2]==0&&no[3]==0&&no[4]==0&&no[5]==0) break;
        double s;
        cin>>s;
        s += eps;

        int value = (int)(s*100.0);
        //cout<<value<<endl;

        for(i=0;i<800;i+=5) { vis[i] = false; ans[i] = 9999;}
        ans[0] = 0;
        vis[0] = true;

        for(i=0;i<6;i++) {
             map<int,bool>mp;
            for(k=0;k<800;k+=5) {

                if(vis[k]&&mp[k]==false) {
                    int cnt = 0;
                    for(int f=k+coin[i];cnt<no[i]&&f<800;f+=coin[i]) {
                        if(ans[f]>(ans[f-coin[i]]+1)) {
                            cnt++;
                            ans[f] = ans[f-coin[i]]+1;
                            vis[f] = true;
                            mp[f] = true;
                        }
                    }
                }
            }
        }

        //for(i=5;i<=100;i+=5) cout<<i<<"  ans [i] : "<<ans[i]<<endl;

        //cout<<ans[95]<<endl;
        for(i=value+5;i<800;i+=5) {
            ans[value] = min(ans[value],ans[i]+dp[i-value]);
        }

        printf("%3d\n",ans[value]);
    }
    return 0;
}
