#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int data[100];

int cmp(const int &a, const int &b)
{
    if(a>b) return 1;
    else return 0;
}

int main()
{
    int t, T,N,S,p;
    freopen("B-large-practice.in.txt","r",stdin);
	freopen("B-large-practice.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d%d%d",&N,&S,&p);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&data[i]);
        }
        sort(data, data+N,cmp);
        int count=0;
        for(int i=0;i<N;i++)
        {
            if(p==0)
            {
                data[i]=-1;
                count++;
            }
            else if(p*3-2<=data[i])
            {
                data[i]=-1;
                count++;
            }
            else break;
        }
        for(int i=0;i<N;i++)
        {
            if(p<2)break;
            if((p*3-4==data[i]||p*3-3==data[i])&&S)
            {
                count++;
                S--;
            }
        }
        printf("Case #%d: %d\n",t,count);
        
    }
    return 0;
}