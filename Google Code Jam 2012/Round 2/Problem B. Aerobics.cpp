#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

long long r[1000][2],pos[1000][3];
int cmp(const void *a, const void *b)
{
    if(((long long*)a)[0]>((long long*)b)[0])
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int cmp2(const void *a, const void *b)
{
    if(((long long*)a)[2]>((long long*)b)[2])
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int t,T,N;
    long long W,L;
    freopen("B-large-practice.in.txt","r",stdin);
	freopen("B-large-practice.out.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%lld%lld",&N,&W,&L);
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&r[i][0]);
            r[i][1]=i;
        }
        qsort(r,N,sizeof(r[0]),cmp);
        srand((unsigned)time(0));
        for(int i=0;i<N;i++)
        {
            while(1)
            {
                pos[i][0]=(long long)(rand()%W);
                pos[i][1]=(long long)(rand()%L);
                pos[i][2]=r[i][1];
                int flag=1;
                for(int j=0;j<i;j++)
                {
                    if((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1])<(r[i][0]+r[j][0])*(r[i][0]+r[j][0]))
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)break;
            }
        }
        qsort(pos,N,sizeof(pos[0]),cmp2);
        printf("Case #%d:",t);
        for(int i=0;i<N;i++)
        {
            printf(" %lld %lld",pos[i][0],pos[i][1]);
        }
        printf("\n");
    }
    return 0;
}