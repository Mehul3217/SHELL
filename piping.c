#include "header.h"

char par2[1000][1000];
long long ar[1000],c=0;
int fd1[2],fd2[2],j=0;
char inp[100],outp2[100],outp[100];
int piping(char input[][1000],int num,int i)
{
	pid_t pid;
	while(i<num)
	{
		int status;
		j=0;
		if(i%2==1)
			pipe(fd1);
		else
			pipe(fd2);
		pid = fork();
		if(pid==0)
		{
			if(i==0)
				dup2(fd2[1],1);
			else if(i==num-1)
			{
				if(num%2!=0)
					dup2(fd1[0],0);
				else
					dup2(fd2[0],0);
			}
			else
			{
				if(i%2!=0)
				{
					dup2(fd2[0],0);
					dup2(fd1[1],1);
				}
				else
				{
					dup2(fd1[0],0);
					dup2(fd2[1],1);
				}
			}
			long long len=strlen(input[i]);
			int in=0,out=0,mehul=0,idx=0;
			c=0;
			for(int l=0;l<len;l++)
			{
				int k=0;
				while(input[i][l]!=' ' && input[i][l]!='\t' && l<len)
				{
					c++;
					par2[j][k]=input[i][l];
					k++;
					l++;
				}
				if(c>0)
				{
					ar[j]=k;
					j++;
				}
				c=0;
			}
			for(int l=0;l<j;l++)
			{
				if(strcmp(par2[l],"<")==0)
				{
					strcpy(inp,par2[l+1]);
					in=1;
				}
				if(strcmp(par2[l],">")==0)
				{
					strcpy(outp,par2[l+1]);
					out=1;
				}
				if(strcmp(par2[l],">>")==0)
				{
					strcpy(outp2,par2[l+1]);
					mehul=1;
				}
			}
			if(in==1 || out==1 || mehul==1)
				redirect(input[i],j,in,out,inp,outp,outp2,mehul);
			else
			{
				char *args[]={par2[0]};
				int h;
				for(h=1;h<j;h++)
					args[h]=par2[h];
				args[h]=NULL;
				if(execvp(args[0],args) < 0)
					perror("Command not found");
			}
			exit(127);
		}
		else
		{
			if(i==0)
				close(fd2[1]);
			else if(i==num-1)
			{
				if(num%2!=0)
					close(fd1[0]);
				else
					close(fd2[0]);
			}
			else
			{
				if(i%2==1)
				{
					close(fd2[0]);
					close(fd1[1]);
				}
				else
				{
					close(fd1[0]);
					close(fd2[1]);
				}
			}
			waitpid(pid,&status,0);
			for(int lo=0;lo<j;lo++)
			{
				for(int k=0;k<ar[lo];k++)
					par2[lo][k]='\0';
			}
			for(int lo=0;lo<strlen(inp);lo++)
				inp[lo]='\0';
			for(int lo=0;lo<strlen(outp);lo++)
				outp[lo]='\0';
			for(int lo=0;lo<strlen(outp2);lo++)
				outp2[lo]='\0';
			for(int lo=0;lo<j;lo++)
				ar[lo]=0;
			i++;
		}
	}
	return 1;
}
