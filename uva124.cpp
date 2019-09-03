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
#define INF (1<<29)
#define ll long long
#define CountOne(mask) __builtin_popcountll(mask)

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
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

bool isVowel(char ch){ch=tolower(ch);if(ch=='a' | ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}

///int dx[]= {-1,-1,0,0,1,1};
///int dy[]= {-1,0,-1,1,0,1};
///int dx[]= {0,0,1,-1};/*4 side move*/
///int dy[]= {-1,1,0,0};/*4 side move*/
///int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
///int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
/*................Code Starts Here................*/

int n, ans[55];
string temp;
bool used[55];
vector<int>graph[55], graph2[55];
map<int, char>mpp;
vector<string>save;

bool cmp(char a, char b) {
    return mpp[a]<mpp[b];
}


void dfs (int v) {
	used[v] = true;
    if(graph2[v].size()==0) { ans[v] = 1; }

    for (int i=0; i<graph2[v].size(); ++i) {
		int to = graph2[v][i];
		if (!used[to]) {
            //cout<<mpp[v]<<" theke "<<mpp[to]<<endl;
            dfs (to);

		}ans[v] = max(ans[v], ans[to]+1);
	}

	for (int i=0; i<graph[v].size(); ++i) {
		int to = graph[v][i];
		if (!used[to]) {
            dfs (to);
            ans[to] = max(ans[to], ans[v]+1);
		}
	}
	temp+=mpp[v];
}

void topological_sort() {
	for (int i=0; i<n; ++i)
		used[i] = ans[i] = false;
	for (int i=0; i<n; ++i)
		if (!used[i]) {
            temp = "";
			dfs (i);
			sort(temp.begin(), temp.end(), cmp);
			save.push_back(temp);
			//cout<<temp<<endl;
		}

}

int main() {
    freopen("input.txt","r",stdin);
    string str, str2;
    while(getline(cin, str)) {
        int i, l = str.size();

        map<char, int>mp;
        mpp.clear();
        int cnt = 0;
        for(i=0;i<l;i+=2) {
            mp[str[i]] = cnt;
            mpp[cnt] = str[i];
            cnt++;
        }
        n = cnt;
        //getchar();
        getline(cin, str2);//cout<<str2<<endl;

        l = str2.size();
        for(i=2;i<l;i+=4) {
            graph[mp[str2[i-2]]].push_back(mp[str2[i]]);
            graph2[mp[str2[i]]].push_back(mp[str2[i-2]]);
            //cout<<mpp[mp[str2[i-2]]]<< " theke "<<mpp[mp[str2[i]]]<<endl;
        }

        topological_sort();
//        for(i=0;i<n;i++) cout<<mpp[i]<<" "<<ans[i]<<endl;
//        cout<<endl;

        l = save.size();
        for(i=0;i<l;i++) cout<<save[i];
        cout<<endl;
        for(i=0;i<l;i++) {
            while(next_permutation())
        }



        for(i=0;i<n;i++) graph[i].clear(), graph2[i].clear();
        save.clear();
    }
    return 0;
}
