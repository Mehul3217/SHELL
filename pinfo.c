#include "header.h"

extern char parse[1000][1000];
void get(char *pre,pid_t pid, char *buf, size_t bufsize)
{
	char s[80],ch[80];
	for(int u=0;u<80;u++)
	{
		ch[u]='\0';
		s[u]='\0';
	}
	strcpy(s,"/proc/");
	int ro=getpid(),u=0;
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
	strcat(s,"/exe");
	ssize_t ret = readlink(s, buf, 512);
	if (ret > 0)
	{
		buf[ret] = 0;
		char try[1001];
		int i=0;
		for(i=0;i<1000;i++)
			try[i]='\0';
		if(strlen(buf)<strlen(pre))
			printf("Executable Path -- %s\n", buf);
		else
		{
			strcpy(try,"~");
			long long l=1;
			i=0;
			while(buf[i]==pre[i])
				i++;
			long long h=strlen(buf);
			while(i<h)
			{
				try[l]=buf[i];
				i++;
				l++;
			}
			printf("Executable Path -- %s\n", try);
		}
	}
	else
		perror("readlink");

	return;
}
void pinf(char *pre)
{
	if(strcmp(parse[1],"\0")==0)
	{
		printf("pid -- %d\n",getpid());
		char s[80],ch[80];
		for(int u=0;u<80;u++)
		{
			ch[u]='\0';
			s[u]='\0';
		}
		strcpy(s,"/proc/");
		int ro=getpid(),u=0;
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
		{
			g[er]='\0';
			gh[er]='\0';
		}
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
			}
			else if(cou==22)
			{
				u=0;
				while(1)
				{
					g[u]=m;
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
		printf("Process Status -- %s\n",gh);
		printf("memory -- %s\n",g);
		char buf[512];
		get(pre,getpid(),buf,512);
		return;
	}
	else
	{
		printf("pid -- %d\n",getpid());
		char s[80],ch[80];
		for(int u=0;u<80;u++)
		{
			ch[u]='\0';
			s[u]='\0';
		}
		int u=0;
		strcpy(s,"/proc/");
		strcat(s,parse[1]);
		strcat(s,"/stat");
		int fd=open(s,O_RDONLY);
		lseek(fd,0,SEEK_SET);
		char m,g[20],gh[20];
		for(int er=0;er<20;er++)
		{
			g[er]='\0';
			gh[er]='\0';
		}
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
			}
			else if(cou==22)
			{
				u=0;
				while(1)
				{
					g[u]=m;
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
		printf("Process Status -- %s\n",gh);
		printf("memory -- %s\n",g);
		char buf[512];
		get(pre,getpid(),buf,512);
		return;
	}
}
