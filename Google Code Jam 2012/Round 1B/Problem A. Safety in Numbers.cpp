#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
int s[210][2];
double m[210][2];
int cmp(const void *a,const void *b)
{
    return ((int*)a)[1]-((int*)b)[1];
}
int cmp2(const void *a,const void *b)
{
    if(((double*)a)[0]>((double*)b)[0])
        return 1;
    else return -1;
}
int main()
{
    int t,T,N;
    freopen("A-large-practice.in.txt","r",stdin);
	freopen("A-large-practice.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        memset(s,0,sizeof(s));
        memset(m,0,sizeof(m));
        scanf("%d",&N);
        int sum=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&s[i][1]);
            sum+=s[i][1];
            s[i][0]=i;
        }
        qsort(s,N,sizeof(s[0]),cmp);
        s[N][1]=s[N-1][1];
        int flag=N-1;
        for(int i=1;i<=N;i++)
        {
            int tmp=0;
            for(int j=i-1;j>=0;j--)
            {
                tmp+=(s[i][1]-s[j][1]);
            }
            if(tmp>=sum)
            {
                flag=i-1;
                break;
            }
        }
        int tmp=sum;
        for(int i=0;i<flag;i++)
        {
            tmp-=(s[flag][1]-s[i][1]);
            m[i][1]=s[flag][1]-s[i][1];
        }
        for(int i=0;i<=flag;i++)
        {
            m[i][1]=(m[i][1]+(double)tmp/(flag+1))/sum*100;
        }
        for(int i=flag+1;i<N;i++)
        {
            m[i][1]=0;
        }
        for(int i=0;i<N;i++)
        {
            m[i][0]=s[i][0];
        }
        qsort(m,N,sizeof(m[0]),cmp2);
        printf("Case #%d:",t);
        for(int i=0;i<N;i++)
        {
            printf(" %.6f",m[i][1]);
        }
        printf("\n");
        
    }
    return 0;
}