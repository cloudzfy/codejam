#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long mote[100];
int main()
{
    int t, T, N;
    long long A;
    freopen("A-large-practice.in.txt","r",stdin);
	freopen("A-large-practice.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld%d", &A, &N);
        for(int i=0; i<N; i++)
        {
            scanf("%lld", &mote[i]);
        }
        if(A==1)
        {
            printf("Case #%d: %d\n",t, N);
            continue;
        }
        sort(mote, mote+N);
        long long count = 0, min = N;
        for(int i=0; i<N; i++)
        {
            int cur = 0;
            if(A<=mote[i]&&min>count+N-i)
            {
                min = count+N-i;
            }
            if(A>mote[i]&&min>count+N-i-1)
            {
                min = count+N-i-1;
            }
            while(A<=mote[i])
            {
                A += A-1;
                cur++;
            }
            if(N-i<cur)
            {
                break;
            }
            else
            {
                count += cur;
            }
            A+=mote[i];
        }
        printf("Case #%d: %lld\n", t, min);
    }
    return 0;
}