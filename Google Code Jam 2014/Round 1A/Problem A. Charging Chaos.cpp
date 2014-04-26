#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;

string outlet[150],device[150];
int main()
{
    int t,T,N,L;
    map<string, int> m;
    freopen("A-large-practice.in.txt","r",stdin);
	freopen("A-large-practice.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d%d",&N,&L);
        for(int i=0;i<N;i++)
        {
            cin>>outlet[i];
        }
        for(int i=0;i<N;i++)
        {
            cin>>device[i];
        }
        m.clear();
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                string tmp="";
                for(int k=0;k<L;k++)
                {
                    if(outlet[i][k]==device[j][k]) tmp+="0";
                    else tmp+="1";
                }
                m[tmp]+=1;
            }
        }
        int ans=L+1;
        for(map<string, int>::iterator i=m.begin();i!=m.end();i++)
        {
            if(i->second==N)
            {
                string tmp=i->first;
                int count=0;
                for(int j=0;j<L;j++)
                {
                    if(tmp[j]=='1')
                    {
                        count++;
                    }
                }
                ans=min(ans,count);
            }
        }
        if(ans==L+1)
        {
            printf("Case #%d: NOT POSSIBLE\n",t);
        }
        else
        {
            printf("Case #%d: %d\n",t,ans);
        }
        
    }
    return 0;
}