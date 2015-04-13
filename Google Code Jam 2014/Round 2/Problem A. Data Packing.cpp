//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int data[10000];
int main(int argc, const char * argv[]) {
    int T,N,X;
    freopen("A-large-practice.in.txt","r",stdin);
    freopen("A-large-practice.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&N,&X);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&data[i]);
        }
        sort(data,data+N);
        int result=0;
        for(int i=N-1,j=0;i>=j;i--)
        {
            if(i==j)
            {
                result++;
            }
            else if(data[i]+data[j]<=X)
            {
                result++;
                j++;
            }
            else
            {
                result++;
            }
        }
        printf("Case #%d: %d\n",t,result);
    }
    return 0;
}
