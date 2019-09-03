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

int main ()
{
    //freopen("input.txt","r",stdin);
    set<string>ignore_list;
    multimap<string, string>result;
    string str, key, temp;

    int i, j, len;

    while(getline(cin,str)&&str!="::") {
        ignore_list.insert(str);
    }

    while(getline(cin,str)) {
        len = str.size();
        for(i=0;i<len;i++) str[i] = tolower(str[i]);
        temp = str;

        for(i=0;i<len;i++) {
            key = "";
            while(isalpha(str[i])) {
                key += str[i++];
            }

            if(key!=""&&!ignore_list.count(key)) {
                for(j=0;j<key.size();j++) key[j] = toupper(key[j]);

                for(j=0;j<key.size();j++) str[i-key.size()+j] = key[j];

                result.insert(make_pair(key,str));
                str = temp;
            }
        }
    }

    for(map<string, string>::iterator it = result.begin();it!=result.end();++it) cout<<it->second<<endl;
    return 0;
}
