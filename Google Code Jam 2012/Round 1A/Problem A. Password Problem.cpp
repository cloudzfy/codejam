#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
double p[100000];

int main()
{
    int t,T,A,B;
    freopen("A-large-practice.in.txt","r",stdin);
	freopen("A-large-practice.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d%d",&A,&B);
        double p_right=1.0;
        for(int i=0;i<A;i++)
        {
            scanf("%lf",&p[i]);
            p_right*=p[i];
        }
        double ans=(B-A+1)*p_right+(2*B-A+2)*(1-p_right);
        if(ans>B+2)
        {
            ans=B+2;
        }
        p_right=1.0;
        for(int i=0;i<A;i++)
        {
            double op=(B-A+(2*(A-i)+1))*p_right+(2*B-A+2*(A-i+1))*(1-p_right);
            if(op<ans)
            {
                ans=op;
            }
            p_right*=p[i];
        }
        printf("Case #%d: %.6f\n",t,ans);
    }
    return 0;
}