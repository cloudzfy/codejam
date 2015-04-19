//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAX(a,b) (a)>(b)?(a):(b)
int m[1000];
int main(int argc, const char * argv[]) {
    int T;
    int N;
    freopen("A-large.in.txt","r",stdin);
    freopen("A-large.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&m[i]);
        }
        int ans1=0,max=0,ans2=0;
        for(int i=1;i<N;i++)
        {
            if(m[i]<m[i-1])
            {
                ans1+=m[i-1]-m[i];
                max=MAX(m[i-1]-m[i],max);
            }
        }
        for(int i=0;i<N-1;i++)
        {
            if(m[i]>max)
            {
                ans2+=max;
            }
            else
            {
                ans2+=m[i];
            }
        }
        printf("Case #%d: %d %d\n",t,ans1,ans2);
    }
    return 0;
}
