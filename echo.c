#include "header.h"

char parse2[1000][1000];
long long ar[1001];
void ech(char *t,char *pre)
{
	long long k=0,j=0,len=strlen(t),i;
	int c=0,c2=0;
	for(i=0;i<len;i++)
	{
		if((int)t[i]==34)
		{
			i++;
			k=0;
			while(t[i]!='"' && i<len)
			{
				parse2[j][k]=t[i];
				i++;
				k++;
				c2++;
			}
			if(c2>0)
			{
				ar[j]=k;
				j++;
			}
			c2=0;
		}
		else
		{
			k=0;
			while(t[i]!=' ' && i<len)
			{
				c++;
				parse2[j][k]=t[i];
				k++;
				i++;
			}
			if(c>0)
			{
				ar[j]=k;
				j++;
			}
			c=0;
		}
	}
	for(i=1;i<j;i++)
		printf("%s ",parse2[i]);
	for(i=0;i<j;i++)
	{
		for(long long l=0;l<ar[i];l++)
			parse2[i][l]='\0';
	}
	printf("\n");
}
