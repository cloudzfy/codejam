//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
#define abs(a) (a)>0?(a):-(a)
#define INF 100000
char str[100][200];
int main(int argc, const char * argv[]) {
    int T,N;
    freopen("A-large-practice.in.txt","r",stdin);
    freopen("A-large-practice.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%s",str[i]);
        }
        char stand[200];
        int count[100][200],x;
        int flag=1;
        memset(stand,0,sizeof(stand));
        memset(count,0,sizeof(count));
        x=0;
        stand[x]=str[0][0];
        count[0][x]++;
        for(int i=1;str[0][i]!=0;i++)
        {
            if(str[0][i]==str[0][i-1])
            {
                count[0][x]++;
            }
            else
            {
                x++;
                stand[x]=str[0][i];
                count[0][x]++;
            }
        }
        x++;
        for(int i=1;i<N;i++)
        {
            int y=0;
            for(int j=0;str[i][j]!=0;j++)
            {
                if(str[i][j]==stand[y])
                {
                    count[i][y]++;
                }
                else if(count[i][y]!=0)
                {
                    y++;
                    if(str[i][j]==stand[y]&&y<x)
                    {
                        count[i][y]++;
                    }
                    else
                    {
                        flag=0;
                    }
                }
                else
                {
                    flag=0;
                }
                if(!flag)break;
            }
            if(y!=x-1)
            {
                flag=0;
            }
            if(!flag)break;
        }
        if(!flag)
        {
            printf("Case #%d: Fegla Won\n",t);
        }
        else
        {
            int result=0;
            for(int i=0;i<x;i++)
            {
                int min=INF,max=0;
                for(int j=0;j<N;j++)
                {
                    min=min(min,count[j][i]);
                    max=max(max,count[j][i]);
                }
                int sum=INF;
                for(int j=min;j<=max;j++)
                {
                    int tmp=0;
                    for(int k=0;k<N;k++)
                    {
                        tmp+=abs(count[k][i]-j);
                    }
                    sum=min(sum,tmp);
                }
                result+=sum;
            }
            printf("Case #%d: %d\n",t,result);
        }
    }
    return 0;
}
