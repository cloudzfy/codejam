//
//  main.cpp
//  codejam
//
//  Created by cloudzfy on 4/12/13.
//  Copyright (c) 2013 cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 10000001
int data[MAX];
void init()
{
    int num[20],j,flag;
    long long tmp;
    freopen("C-large-1.in.txt","r",stdin);
	freopen("C-large-1.out.txt","w",stdout);
    memset(data,0,sizeof(data));
    for(int i=0;i<MAX;i++)
    {
        tmp=(long long)i*i;
        j=0;
        while(tmp!=0)
        {
            num[j]=tmp%10;
            tmp=tmp/10;
            j++;
        }
        flag=1;
        for(int k=0;k<j;k++)
        {
            if(num[k]!=num[j-k-1])
            {
                flag=0;
                break;
            }
        }
        tmp=i;
        j=0;
        while(tmp!=0)
        {
            num[j]=tmp%10;
            tmp=tmp/10;
            j++;
        }
        for(int k=0;k<j;k++)
        {
            if(num[k]!=num[j-k-1])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            data[i]=1;
        }
    }
    for(int i=1;i<MAX;i++)
    {
        data[i]=data[i-1]+data[i];
    }
}
int main()
{
    long long A,B;
    int T;
    init();
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%lld%lld",&A,&B);
        int a=(int)sqrt(A);
        int b=(int)sqrt(B);
        if(a*a==A) a--;
        printf("Case #%d: %d\n",t,data[b]-data[a]);
    }
    return 0;
}