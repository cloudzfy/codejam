#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
double a[1000],b[1000];
int main()
{
    int t,T,N,y,z;
    freopen("D-large-practice.in.txt","r",stdin);
	freopen("D-large-practice.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%lf",&a[i]);
        }
        for(int i=0;i<N;i++)
        {
            scanf("%lf",&b[i]);
        }
        sort(a,a+N);
        sort(b,b+N);
        y=0;
        for(int i=0,j=0;i<N;i++)
        {
            if(a[i]>b[j])
            {
                y++;
                j++;
            }
        }
        z=0;
        for(int i=0,j=0;j<N;j++)
        {
            if(a[i]<b[j])
            {
                z++;
                i++;
            }
        }
        z=N-z;
        printf("Case #%d: %d %d\n",t,y,z);
    }
    return 0;
}