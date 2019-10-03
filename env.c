#include "header.h"

extern char parse[1000][1000],*en[1000];
long long cou;
void env()
{
	int i=0;
	if(strcmp(parse[i],"setenv")==0)
	{
		if(strcmp(parse[i+1],"\0")==0)
			perror("Insuffcient Command Line Arguments");
		else if(strcmp(parse[i+3],"\0")!=0)
			perror("Extra Command Line Arguments");
		else
		{
			long long gg=0,leni=strlen(parse[i+2]);
			char df[1001];
			for(int i=0;i<1000;i++)
				df[i]='\0';
			for(long long po=0;po<leni;po++)
			{
				if(parse[i+2][po]=='[' || parse[i+2][po]==']')
					continue;
				df[gg]=parse[i+2][po];
				gg++;
			}
			char du[1000];
			for(int y=0;y<1000;y++)
				du[y]='\0';
			gg=0;
			int c=0;
			for(long long j=0;j<cou;j++)
			{
				long long h=strlen(en[j]);
				for(long long k=0;k<h;k++)
				{
					if(en[j][k]=='=')
						break;
					du[gg]=en[j][k];
					gg++;
				}
				if(strcmp(du,parse[i+1])==0)
				{
					c++;
					for(long long u=0;u<h;u++)
						en[j][u]='\0';
					strcat(du,"=");
					strcat(du,df);
					en[j]=strdup(du);
					break;
				}
				for(int y=0;y<1000;y++)
					du[y]='\0';
				gg=0;
			}
			if(c==0)
			{
				strcat(parse[i+1],"=");
				strcat(parse[i+1],df);
				en[cou]=strdup(parse[i+1]);
				cou++;
			}
		}
	}
	else if(strcmp(parse[i],"unsetenv")==0)
	{
		if(strcmp(parse[i+1],"\0")==0)
			perror("Insuffcient Command Line Arguments");
		else
		{
			char du[1000];
			for(int y=0;y<1000;y++)
				du[y]='\0';
			int gg=0,c=0;
			for(long long j=0;j<cou;j++)
			{
				long long h=strlen(en[j]);
				for(long long k=0;k<h;k++)
				{
					if(en[j][k]=='=')
						break;
					du[gg]=en[j][k];
					gg++;
				}
				if(strcmp(du,parse[i+1])==0)
				{
					c++;
					for(long long u=0;u<h;u++)
						en[j][u]='\0';
					break;
				}
				for(int y=0;y<1000;y++)
					du[y]='\0';
				gg=0;
			}
			if(c==0)
				printf("No Environment Variable Found\n");
		}
	}
}
