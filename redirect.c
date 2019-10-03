#include "header.h"

char parse2[1000][1000];
long long ar[1001];
void redirect(char *t,int j,int in ,int out,char inp[],char outp[],char outp2[],int mehul)
{
	long long c=0,c2=0,k=0,l=0,len=strlen(t),i;
	for(i=0;i<1000;i++)
	{
		for(int u=0;u<1000;u++)
			parse2[i][u]='\0';
	}
	for(i=0;i<len;i++)
	{
		if((int)t[i]==34)
		{
			i++;
			k=0;
			while(t[i]!='"' && i<len)
			{
				parse2[l][k]=t[i];
				i++;
				k++;
				c2++;
			}
			if(c2>0)
			{
				ar[l]=k;
				l++;
			}
			c2=0;
		}
		else
		{
			k=0;
			while(t[i]!=' ' && i<len)
			{
				c++;
				parse2[l][k]=t[i];
				k++;
				i++;
			}
			if(c>0)
			{
				ar[l]=k;
				l++;
			}
			c=0;
		}
	}
	int fd1,fd2;
	int save_stdin = dup(STDIN_FILENO);
	int save_stdout = dup(1);
	pid_t pid=fork();
	if(pid==0)
	{
		if(in==1)
		{
			fd1=open(inp,O_RDONLY);
			if(fd1<0)
			{
				perror("File not found");
				exit(127);
			}
			dup2(fd1,0);
			close(fd1);
		}
		if(out==1 || mehul==1)
		{
			if(mehul==0)
				fd2=open(outp, O_CREAT | O_WRONLY | O_TRUNC ,0644);
			else
				fd2=open(outp2, O_CREAT | O_WRONLY | O_APPEND  ,0644);
			if(fd2<0)
			{
				perror("File not found");
				exit(127);
			}
			dup2(fd2,1);
			close(fd2);
		}
		i=0;
		int h;
		char *args[]={parse2[i]};
		for(h=1;h<j;h++)
		{
			args[h]=parse2[h];
			if(strcmp(args[h],">")==0 || strcmp(args[h],"<")==0 || strcmp(args[h],">>")==0)
				args[h]=NULL;
		}
		args[h]=NULL;
		if(execvp(parse2[i],args)<0)
			perror("Command not found");
		exit(127);
	}
	else
	{
		wait(NULL);
		dup2(save_stdin,STDIN_FILENO);
		close(save_stdin);
		dup2(save_stdout,1);
		close(save_stdout);
	}
	return;
}
