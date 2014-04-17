//
//  main.cpp
//  codejam
//
//  Created by cloudzfy on 4/12/13.
//  Copyright (c) 2013 cloudzfy. All rights reserved.
//

#include <stdio.h>

char map[4][5];
int main()
{
    int T,tmpX,tmpO,tmpT,tmpD,ans;
    freopen("A-large.in.txt","r",stdin);
	freopen("A-large.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        ans=0;
        for(int i=0;i<4;i++)
        {
            scanf("%s",map[i]);
        }
        for(int i=0;i<4;i++)
        {
            tmpX=0;
            tmpO=0;
            tmpT=0;
            for(int j=0;j<4;j++)
            {
                if(map[i][j]=='X')
                {
                    tmpX++;
                }
                else if(map[i][j]=='O')
                {
                    tmpO++;
                }
                else if(map[i][j]=='T')
                {
                    tmpT++;
                }
            }
            if(tmpX+tmpT==4)
            {
                ans=1;
            }
            if(tmpO+tmpT==4)
            {
                ans=2;
            }
        }
        if(ans==0)
        {
            for(int j=0;j<4;j++)
            {
                tmpX=0;
                tmpO=0;
                tmpT=0;
                for(int i=0;i<4;i++)
                {
                    if(map[i][j]=='X')
                    {
                        tmpX++;
                    }
                    else if(map[i][j]=='O')
                    {
                        tmpO++;
                    }
                    else if(map[i][j]=='T')
                    {
                        tmpT++;
                    }
                }
                if(tmpX+tmpT==4)
                {
                    ans=1;
                }
                if(tmpO+tmpT==4)
                {
                    ans=2;
                }
            }
        }
        if(ans==0)
        {
            tmpX=0;
            tmpO=0;
            tmpT=0;
            for(int i=0;i<4;i++)
            {
                if(map[i][i]=='X')
                {
                    tmpX++;
                }
                else if(map[i][i]=='O')
                {
                    tmpO++;
                }
                else if(map[i][i]=='T')
                {
                    tmpT++;
                }
            }
            if(tmpX+tmpT==4)
            {
                ans=1;
            }
            if(tmpO+tmpT==4)
            {
                ans=2;
            }
        }
        if(ans==0)
        {
            tmpX=0;
            tmpO=0;
            tmpT=0;
            for(int i=0;i<4;i++)
            {
                if(map[i][3-i]=='X')
                {
                    tmpX++;
                }
                else if(map[i][3-i]=='O')
                {
                    tmpO++;
                }
                else if(map[i][3-i]=='T')
                {
                    tmpT++;
                }
            }
            if(tmpX+tmpT==4)
            {
                ans=1;
            }
            if(tmpO+tmpT==4)
            {
                ans=2;
            }
        }
        if(ans==0)
        {
            tmpD=0;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(map[i][j]=='.')
                    {
                        tmpD++;
                        break;
                    }
                }
                if(tmpD!=0)break;
            }
            if(tmpD!=0)ans=4;
            else ans=3;
        }
        if(ans==1)
        {
            printf("Case #%d: X won\n",t);
        }
        else if(ans==2)
        {
            printf("Case #%d: O won\n",t);
        }
        else if(ans==3)
        {
            printf("Case #%d: Draw\n",t);
        }
        else if(ans==4)
        {
            printf("Case #%d: Game has not completed\n",t);
        }
        
    }
    return 0;
}