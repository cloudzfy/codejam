#include <stdio.h>
int x[26]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
char str[200];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int t,T,i;
	scanf("%d",&T);
	getchar();
	for(t=1;t<=T;t++)
	{
		gets(str);
		for(i=0;str[i]!=0;i++)
		{
			if(str[i]==' ')continue;
			str[i]=x[str[i]-'a']+'a';
		}
		printf("Case #%d: %s\n",t,str);
	}
}