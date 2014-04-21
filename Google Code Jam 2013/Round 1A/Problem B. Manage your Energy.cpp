#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

long long v[10000], s[10000], used[10000];

int main()
{
    stack<int> n;
    int t, T, E, R, N;
    long long cur;
    long long ans;
    freopen("B-large-practice.in.txt","r",stdin);
	freopen("B-large-practice.out.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d%d", &E, &R, &N);
        for(int i=0; i<N; i++)
        {
            scanf("%lld", &v[i]);
        }
        while(!n.empty())
        {
            n.pop();
        }
        for(int i=N-1; i>=0; i--)
        {
            while(!n.empty())
            {
                if(v[i] >= v[n.top()])
                {
                    n.pop();
                }
                else break;
            }
            if(n.empty())
            {
                s[i] = N - i;
            }
            else
            {
                s[i] = n.top() - i;
            }
            n.push(i);
        }
        cur = E;
        memset(used, 0,sizeof(used));
        for(int i=0; i<N-1; i++)
        {
            if(s[i]+i<N)
            {
                if(cur+s[i]*R-E>0)
                {
                    used[i]=cur+s[i]*R-E;
                    if(used[i]>E) used[i]=E;
                    if(used[i]>cur) used[i]=cur;
                }
            }
            else
            {
                used[i]=cur;
            }
            cur=cur-used[i]+R;
            if(cur>E) cur = E;
        }
        used[N-1]= cur;
        ans = 0;
        for(int i=0; i<N; i++)
        {
            ans += used[i] * v[i];
        }
        printf("Case #%d: %lld\n",t, ans);
    }
    return 0;
}