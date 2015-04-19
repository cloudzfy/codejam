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
long long x[1000];
int main(int argc, const char * argv[]) {
    int T;
    int B;
    long long N;
    freopen("B-large-practice.in.txt","r",stdin);
    freopen("B-large-practice.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%lld",&B,&N);
        int max=0;
        for(int i=0;i<B;i++)
        {
            scanf("%d",&m[i]);
            max=MAX(max,m[i]);
        }
        long long left=0,right=N*max;
        long long mid;
        do
        {
            mid=(left+right)/2;
            long long sum=0;
            for(int i=0;i<B;i++)
            {
                sum+=mid/m[i];
            }
            if(sum<N) left=mid;
            else right=mid;
        }while(right-left>1);
        long long mm=0,sum=0,ths=right*100000;
        int index=0;
        for(int i=0;i<B;i++)
        {
            x[i]=left/m[i];
            if(ths>x[i]*m[i])
            {
                ths=x[i]*m[i];
            }
        }
        for(int i=0;i<B;i++)
        {
            x[i]=ths/m[i];
            sum+=x[i];
        }
        if(sum==N)
        {
            mm=0;
            for(int i=0;i<B;i++)
            {
                if(mm<=x[i]*m[i])
                {
                    mm=x[i]*m[i];
                    index=i;
                }
            }
        }
        while(sum<N)
        {
            mm=right*100000;
            for(int i=0;i<B;i++)
            {
                if(mm>x[i]*m[i])
                {
                    mm=x[i]*m[i];
                    index=i;
                }
            }
            x[index]++;
            sum++;
        }
        printf("Case #%d: %d\n",t,index+1);
    }
    return 0;
}
