#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int data[10001][3];
int main()
{
    int t,T,N,D;
    freopen("A-large-practice.in.txt","r",stdin);
	freopen("A-large-practice.out.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&N);
        memset(data,0,sizeof(data));
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        scanf("%d",&D);
        data[0][2]=data[0][0];
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(data[i][2]+data[i][0]>=data[j][0])
                {
                    data[j][2]=max(min(data[j][0]-data[i][0],data[j][1]),data[j][2]);
                }
                else break;
            }
        }
        int flag=0;
        for(int i=N-1;i>=0;i--)
        {
            if(data[i][0]+data[i][2]>=D)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            printf("Case #%d: YES\n",t);
        }
        else
        {
            printf("Case #%d: NO\n",t);
        }
    }
    return 0;
}