#include "header.h"

char str[100010],parse[1000][1000],name[1000][1000],varu[1000],*en[1000];
long long ar[1001];
char s[1001],stm[100001];
char arr[1000][1000];
long long idx=0,go=0,cou=0;
char wq[100010];
long long job[1000],id=1;
pid_t ppiidd=-1;

void handler(int signum)
{
	printf("\n");
	if(signum==SIGTSTP && ppiidd>=0)
	{
		job[id]=ppiidd;
		strcpy(name[id],varu);
		id++;
		kill(ppiidd,signum);
		ppiidd=-1;
		printf("[%lld]+ Stopped			%s\n",id-1,name[id-1]);
	}
	else if(ppiidd>=0 && signum==SIGINT)
	{
		kill(ppiidd,signum);
		ppiidd=-1;
	}
}


int main(int argc,char *argv[],char *envp[])
{
	signal(SIGTTOU,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);
	signal(SIGINT,handler);
	signal(SIGTSTP,handler);
	char pre[1001];
	getcwd(pre,sizeof(pre));
	printf("\e[1;1H\e[2J");
	printf("Type 'quit' to close\n\n");
	prompt("~");
	int fd=open("historyfile",O_CREAT | O_RDONLY,0777);
	FILE * fp;
	char * line = NULL;
	ssize_t len;
	ssize_t read;
	fp = fopen("historyfile", "r");
	while ((read = getline(&line, &len, fp)) != -1)
		add(line);
	for(int i=0;i<1000;i++)
		en[i]=NULL;
	for(int i=0;envp[i]!=NULL;i++)
	{
		en[i]=strdup(envp[i]);
		cou++;
	}
	while(1)
	{
		for(long long int i=0;i<100000;i++)
			str[i]='\0';
		if(input(pre)==-1)
			continue;
		long long c=0,mehul=strlen(str),summ=0;
		for(long long i=0;i<mehul;i++)
		{
			summ+=(int)str[i];
			if(summ==183 && (i+1)%3==0)
			{
				c++;
				summ=0;
			}
		}
		if(c>0)
		{
			long long up=c;
			char pr[1001];
			getcwd(pr,sizeof(pr));
			clea(pr);
			for(long long y=0;y<100000;y++)
				wq[y]='\0';
			if(arr[idx-up][strlen(arr[idx-up])-1]=='\n')
				arr[idx-up][strlen(arr[idx-up])-1]='\0';
			strcpy(wq,arr[idx-up]);
			printf("%s\n",wq);
			add(arr[idx-up]);
			int a=parsing(wq,pr);
			if(a==0)
				return 0;
		}
		else
		{
			add(str);
			int a=parsing(str,pre);
			if(a==0)
				return 0;
		}
	}
	return 0;
}
