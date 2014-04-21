//
//  main.cpp
//  topcoder
//
//  Created by cloudzfy on 4/9/13.
//  Copyright (c) 2013 cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return ((int*)b)[1]-((int*)a)[1];
}

int x[1000][2],s[1000];
int main()
{
    int T,N,i,star,ans;
    //freopen("B-small-practice.in.txt","r",stdin);
    //freopen("B-small-practice.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        memset(s,0,sizeof(s));
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d %d",&x[i][0],&x[i][1]);
        }
        star=0;
        ans=0;
        int tmp;
        qsort(x,N,sizeof(x[0]),cmp);
        while(star<N*2)
        {
            tmp=0;
            for(i=0;i<N;i++)
            {
                if(s[i]<2&&x[i][1]<=star)
                {
                    star+=(2-s[i]);
                    s[i]=2;
                    tmp=1;
                    ans++;
                    break;
                }
            }
            if(!tmp)
            {
                for(i=0;i<N;i++)
                {
                    if(s[i]<1&&x[i][0]<=star)
                    {
                        star+=(1-s[i]);
                        s[i]=1;
                        tmp=1;
                        ans++;
                        break;
                    }
                }
            }
            if(!tmp)
            {
                break;
            }
        }
        if(tmp)
        {
            printf("Case #%d: %d\n",t,ans);
        }
        else
        {
            printf("Case #%d: Too Bad\n",t);
        }
    }
    return 0;
}