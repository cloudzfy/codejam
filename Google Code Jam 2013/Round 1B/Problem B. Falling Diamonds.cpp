//
//  main.cpp
//  codejam
//
//  Created by cloudzfy on 5/4/13.
//  Copyright (c) 2013 cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;
double dp[10010][10010];
void cal(int x)
{
    dp[0][0]=1;
    for(int i=1;i<=x;i++)
    {
        dp[i][0]=dp[i-1][0]*0.5;
        dp[0][i]=dp[0][i-1]*0.5;
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(i!=x&&j!=x)dp[i][j]=dp[i-1][j]*0.5+dp[i][j-1]*0.5;
            else if(i==x&&j!=x)dp[i][j]=dp[i-1][j]*0.5+dp[i][j-1];
            else if(i!=x&&j==x)dp[i][j]=dp[i-1][j]+dp[i][j-1]*0.5;
            else if(i==x&&j==x)dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
}

int main()
{
    int T,N,X,Y;
    freopen("B-large-practice.in.txt","r",stdin);
	freopen("B-large-practice.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d%d",&N,&X,&Y);
        int level = (abs(X)+Y)/2+1;
        int sum=0;
        int n;
        for(n=1;;n++)
        {
            sum+=4*n-3;
            if(sum>=N)break;
        }
        if(n==level)
        {
            if(sum==N) printf("Case #%d: 1.0\n",t);
            else if(Y+1>N-sum+4*n-3||X==0) printf("Case #%d: 0.0\n",t);
            else
            {
                sum-=4*n-3;
                cal(2*n-2);
                double result=0;
                for(int i=Y+1;N-sum-i>=0;i++)
                {
                    if(N-sum-i>2*n-2||i>2*n-2)continue;
                    result+=dp[i][N-sum-i];
                }
                printf("Case #%d: %.6f\n",t,result);
            }
        }
        else if(n<level)
        {
            printf("Case #%d: 0.0\n",t);
        }
        else
        {
            printf("Case #%d: 1.0\n",t);
        }
        
    }
    return 0;
}