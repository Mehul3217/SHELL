#include "header.h"

extern char parse[1000][1000],name[1000][1000];
extern long long job[1000],id;
void bg()
{
	int i=0;
	if(strcmp(parse[i+1],"\0")==0)
		printf("Insufficient Arguments\n");
	else
	{
		if(job[atoi(parse[i+1])]==0)
			printf("No such Job exists\n");
		else
		{
			char s[80],ch[80];
			for(int u=0;u<80;u++)
			{
				ch[u]='\0';
				s[u]='\0';
			}
			strcpy(s,"/proc/");
			int ro=job[atoi(parse[i+1])],u=0;
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
			if(strcmp(gh,"S")!=0)
				kill(job[atoi(parse[i+1])],18);
		}
	}
}
