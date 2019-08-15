#include<iostream>
#include<map>
#include<cstring>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);

    while(T--)
    {

    }
    return 0;

}



/*map<string,int>frnd;
    long long int T,F,cnt;
    string s1,s2;

    cin>>T;
    while(T--)
    {
        cnt=0;
        cin>>F;
        while(F--)
        {
            cin>>s1>>s2;
            if((frnd.find(s1)->second<1)&&(frnd.find(s2)->second<1))
            {
                cnt=2;
                frnd.insert(pair<string,int>(s1,cnt));
                frnd.insert(pair<string,int>(s2,cnt));
            }
            else
            {
                if(frnd.find(s1)->second<1)
                {
                    cnt=frnd.find(s1)->second+1;
                    frnd.insert(pair<string,int>(s1,cnt));
                }
                if(frnd.find(s2)->second<1)
                {
                    cnt=frnd.find(s2)->second+1;
                    frnd.insert(pair<string,int>(s2,cnt));
                }
            }
            cout<<cnt<<endl;
        }
        frnd.clear();
    }*/
