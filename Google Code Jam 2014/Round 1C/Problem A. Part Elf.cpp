//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>

long long base[41];
int main(int argc, const char * argv[]) {
    int T;
    long long P,Q;
    base[0]=1;
    for(int i=1;i<41;i++)
    {
        base[i]=base[i-1]*2;
    }
    freopen("A-large-practice.in.txt","r",stdin);
    freopen("A-large-practice.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%lld/%lld",&P,&Q);
        int x,y;
        for(x=1;x<41;x++)
        {
            if(base[x]>Q)break;
            if(Q%base[x]==0)continue;
            else break;
        }
        long long q=Q/base[x-1];
        if(P%q!=0)
        {
            printf("Case #%d: impossible\n",t);
            continue;
        }
        if(P/q>base[x-1])
        {
            printf("Case #%d: impossible\n",t);
            continue;
        }
        else
        {
            P/=q;
            y=0;
            while(1)
            {
                y++;
                P*=2;
                if(P>=base[x-1]) break;
            }
            printf("Case #%d: %d\n",t,y);
        }
    }
    return 0;
}
