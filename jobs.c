#include "header.h"

extern char name[1000][1000];
extern long long job[1000],id;
void jobs()
{
	for(long long int py=1;py<id;py++)
	{
		char s[80],ch[80];
		for(int u=0;u<80;u++)
		{
			ch[u]='\0';
			s[u]='\0';
		}
		strcpy(s,"/proc/");
		int ro=job[py],u=0;
		while(ro>0)
		{
			ch[u]=(char)(ro%10+48);
			u++;
			ro/=10;
		}
		int st=0,end=u-1;
		char f;
		while(st<end)
		{
			f=ch[st];
			ch[st]=ch[end];
			ch[end]=f;
			st++;
			end--;
		}
		strcat(s,ch);
		strcat(s,"/stat");
		int fd=open(s,O_RDONLY);
		if(fd<0)
			continue;
		lseek(fd,0,SEEK_SET);
		char m,g[20],gh[20];
		for(int er=0;er<20;er++)
			gh[er]='\0';
		int cou=0;
		u=0;
		while(1)
		{
			read(fd,&m,1);
			if(cou==2)
			{
				while(1)
				{
					gh[u]=m;
					u++;
					read(fd,&m,1);
					if(m==' ')
						break;
				}
				break;
			}
			if(m==' ')
				cou++;
		}
		char stst[40];
		for(int h=0;h<40;h++)
			stst[h]='\0';
		if(strcmp(gh,"T")==0)
			strcpy(stst,"Stopped");
		else if(strcmp(gh,"R")==0)
			strcpy(stst,"Running");
		else if(strcmp(gh,"S")==0)
			strcpy(stst,"Running");
		if(job[py]==0)
			continue;
		printf("[%lld] %s %s [%lld]\n",py,stst,name[py],job[py]);
	}

}
