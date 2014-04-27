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

int a[1000],m[1000][1000],tt[120][3];
int cmp(const void *a, const void *b)
{
    return ((int*)a)[1]-((int*)b)[1];
}
int cmp2(const void *a, const void *b)
{
    return ((int*)a)[0]-((int*)b)[0];
}
int main()
{
    int t,T,N;
    freopen("C-small-practice.in.txt","r",stdin);
	freopen("C-small-practice.out.txt","w",stdout);
    srand((unsigned)time(0));
    for(int i=0;i<3000000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            a[j]=j;
        }
        for(int j=0;j<1000;j++)
        {
            swap(a[j],a[rand()%1000]);
        }
        for(int j=0;j<1000;j++)
        {
            m[j][a[j]]++;
        }
    }
    scanf("%d", &T);
    for(t=0; t<T; t++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            int data;
            scanf("%d",&data);
            tt[t][1]+=m[i][data];
            tt[t][0]=t;
        }
    }
    qsort(tt,T,sizeof(tt[0]),cmp);
    for(int t=0;t<T;t++)
    {
        if(t<T/2)tt[t][2]=1;
        else tt[t][2]=0;
    }
    qsort(tt,T,sizeof(tt[0]),cmp2);
    for(int t=0;t<T;t++)
    {
        if(tt[t][2])printf("Case #%d: GOOD\n",t+1);
        else printf("Case #%d: BAD\n",t+1);
    }
    return 0;
}