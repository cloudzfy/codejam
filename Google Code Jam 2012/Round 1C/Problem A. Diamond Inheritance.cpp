#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

int map[1000][1000],label[1000],N;

int dfs(int v)
{
    stack<int> s;
    int cur;
    memset(label,0,sizeof(label));
    s.push(v);
    while(!s.empty())
    {
        cur = s.top();
        s.pop();
        if(!label[cur])
        {
            label[cur]=1;
            for(int i=0;i<N;i++)
            {
                if(map[cur][i])
                {
                    s.push(i);
                }
            }
        }
        else return 1;
    }
    return 0;
}
int main()
{
    int t,T,m,x;
    freopen("A-large-practice.in.txt","r",stdin);
	freopen("A-large-practice.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        memset(map,0,sizeof(map));
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&x);
                map[i][x-1]=1;
            }
        }
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(dfs(i))
            {
                ans=1;
                break;
            }
        }
        if(ans)
        {
            printf("Case #%d: Yes\n",t);
        }
        else
        {
            printf("Case #%d: No\n",t);
        }
    }
    return 0;
}