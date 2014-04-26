#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    int t,T,X,Y;
    stack<char> s;
    freopen("B-large-practice.in.txt","r",stdin);
	freopen("B-large-practice.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d%d",&X,&Y);
        int N=0,sum=0;
        while(sum<abs(X)+abs(Y)||(sum+X+Y)%2==1)
        {
            N+=1;
            sum+=N;
        }
        while(N>0)
        {
            if(abs(X)>abs(Y))
            {
                if(X>0)
                {
                    X-=N;
                    s.push('E');
                }
                else
                {
                    X+=N;
                    s.push('W');
                }
            }
            else
            {
                if(Y>0)
                {
                    Y-=N;
                    s.push('N');
                }
                else
                {
                    Y+=N;
                    s.push('S');
                }
            }
            N--;
        }
        printf("Case #%d: ",t);
        while(!s.empty())
        {
            printf("%c",s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}