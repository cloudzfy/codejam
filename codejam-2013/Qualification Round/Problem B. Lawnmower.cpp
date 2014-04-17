//
//  main.cpp
//  codejam
//
//  Created by cloudzfy on 4/12/13.
//  Copyright (c) 2013 cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int N,M,map[100][100],x[100][100];

int main()
{
    int T,flag;
    freopen("B-large.in.txt","r",stdin);
	freopen("B-large.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        memset(x,0,sizeof(x));
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        for(int k=0;k<N+M;k++)
        {
            int min=200,mark[2];
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                    if(!x[i][j]&&map[i][j]<min)
                    {
                        mark[0]=i;
                        mark[1]=j;
                        min=map[i][j];
                    }
                }
            }
            flag=1;
            for(int i=0;i<N;i++)
            {
                if(!x[i][mark[1]]&&map[i][mark[1]]!=map[mark[0]][mark[1]])
                {
                    flag=0;
                    break;
                }
            }
            if(!flag)
            {
                flag=2;
                for(int j=0;j<M;j++)
                {
                    if(!x[mark[0]][j]&&map[mark[0]][j]!=map[mark[0]][mark[1]])
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1)
            {
                for(int i=0;i<N;i++)
                {
                    x[i][mark[1]]=1;
                }
            }
            else if(flag==2)
            {
                for(int j=0;j<M;j++)
                {
                    x[mark[0]][j]=1;
                }
            }
            else break;
        }
        if(flag==0)
        {
            printf("Case #%d: NO\n",t);
        }
        else
        {
            printf("Case #%d: YES\n",t);
        }
    }
    return 0;
}