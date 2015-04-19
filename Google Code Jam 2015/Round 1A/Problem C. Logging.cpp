//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define MIN(a,b) (a)<(b)?(a):(b)
#define eps 1e-15
struct point
{
    int x,y;
}P[3000];
long double s[6000];
int main(int argc, const char * argv[]) {
    int T;
    int N;
    freopen("C-large-practice.in.txt","r",stdin);
    freopen("C-large-practice.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&P[i].x,&P[i].y);
        }
        printf("Case #%d:\n",t);
        for(int i=0;i<N;i++)
        {
            int count=0;
            for(int j=0;j<N;j++)
            {
                if(i==j)continue;
                s[count++]=atan2l(P[j].y-P[i].y,P[j].x-P[i].x);
            }
            for(int j=count;j<count*2;j++)
            {
                s[j]=s[j-count]+2*M_PI;
            }
            sort(s,s+2*count);
            int k=0;
            int ans=count;
            for(int j=0;j<count;j++)
            {
                while(s[k]-s[j]-M_PI<-eps)
                    k++;
                ans=MIN(k-j-1,ans);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
