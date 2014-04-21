#include <stdio.h>
#include <string.h>
long long pow(long long x, long long n)
{
    long long ans=1;
    while(n--)
    {
        ans*=x;
    }
    return ans;
}
int main()
{
    int t, T;
    long long N, P, M, y, z;
    freopen("B-large-practice.in.txt","r",stdin);
	freopen("B-large-practice.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld%lld", &N, &P);
        M=pow(2,N);
        long long tmp = M, count = 0;
        while(tmp>P)
        {
            tmp/=2;
            count++;
        }
        z=M-pow(2,count);
        tmp=0;
        count=0;
        if(M==P)
        {
            y=M-1;
        }
        else
        {
            while(tmp<P)
            {
                tmp+=((long long)1<<(N-count-1));
                count++;
            }
            y=pow(2,count)-2;
        }
        printf("Case #%d: %lld %lld\n", t, y, z);
    }
    return 0;
}