#include "header.h"

char cmd[1000][1000];
extern char str[100010],parse[1000][1000];
extern long long ar[1001];
extern long long int job[1000],id;
extern char name[1000][1000],varu[1000],*en[1000];
extern char arr[1000][1000];
extern long long idx,ppiidd,cou;

void dela(long long n)
{
	long long t=1000*n;
	clock_t time=clock();
	while(clock() < time + t)
		;
}

int parsing(char *str2,char *pre)
{
	long long i,l,len=strlen(str2),j=0,k=0;
	int c=0,lol=0;
	int key=0,in=0,out=0,mehul=0;
	char inp[256],outp[256],outp2[256];
	char *t = strtok(str2,";");
	while(t!=NULL)
	{
		for(int pp=0;pp<1000;pp++)
		{
			for(int yu=0;yu<1000;yu++)
				cmd[pp][yu]='\0';
		}
		j=0;
		len=strlen(t);
		for(i=0;i<256;i++)
		{
			inp[i]='\0';
			outp[i]='\0';
			outp2[i]='\0';
		}
		for(i=0;i<len;i++)
		{
			k=0;
			while(t[i]!=' ' && t[i]!='\t' && i<len)
			{
				c++;
				parse[j][k]=t[i];
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
		int pip=0,pure=0;
		for(i=0;i<j;i++)
		{
			if(strcmp(parse[i],"|")==0)
				pip++;
		}
		for(int l=0;l<j;l++)
		{
			if(strcmp(parse[l],"<")==0)
			{
				strcpy(inp,parse[l+1]);
				in=1;
			}
			if(strcmp(parse[l],">")==0)
			{
				strcpy(outp,parse[l+1]);
				out=1;
			}
			if(strcmp(parse[l],">>")==0)
			{
				strcpy(outp2,parse[l+1]);
				mehul=1;
			}
		}
		int m1=0,m2=0;
		while(m1<pip+1)
		{
			for(;m2<j;m2++)
			{
				if(strcmp(parse[m2],"|")!=0)
				{
					strcat(cmd[m1],parse[m2]);
					if(!((m2+1)>=j))
						strcat(cmd[m1]," ");
				}
				else
				{
					m2++;
					break;
				}
			}
			m1++;
		}
		for(int y=0;y<1000;y++)
			cmd[m1][y]='\0';
		i=0;
		int num=0;
		if(strcmp(parse[j-1],"&")!=0)
		{
			if(pip>0)
			{
				int save_stdin = dup(STDIN_FILENO);
				int save_stdout = dup(1);
				piping(cmd,(pip+1),0);
				for(int ppo=0;ppo<m1;ppo++)
				{
					int len=strlen(cmd[ppo]);
					for(int ppi=0;ppi<len;ppi++)
						cmd[ppo][ppi]='\0';
				}
				fflush(stdout);
				fflush(stdin);
				dup2(save_stdin,STDIN_FILENO);
				close(save_stdin);
				dup2(save_stdout,1);
				close(save_stdout);
				fflush(stdout);
				fflush(stdin);
			}
			else if(in==1 || out==1 || mehul==1)
			{
				int save_stdin = dup(STDIN_FILENO);
				int save_stdout = dup(1);
				redirect(t,j,in,out,inp,outp,outp2,mehul);
				fflush(stdout);
				fflush(stdin);
				dup2(save_stdin,STDIN_FILENO);
				close(save_stdin);
				dup2(save_stdout,1);
				close(save_stdout);
				fflush(stdout);
				fflush(stdin);
			}
			else if(strcmp(parse[i],"setenv")==0 || strcmp(parse[i],"unsetenv")==0)
				env();
			else if(strcmp("nightswatch",parse[i])==0)
				night();
			else if(strcmp("history",parse[i])==0)
			{
				if(strcmp(parse[i+1],"\0")!=0)
					num=atoi(parse[i+1]);
				hist(num);
			}
			else if(strcmp("pinfo",parse[i])==0)
				pinf(pre);
			else if(strcmp("quit",parse[i])==0)
			{
				exe();
				return 0;
			}
			else if(strcmp("clear",parse[i])==0 || strcmp("reset",parse[i])==0)
				printf("\e[1;1H\e[2J");
			else if(strcmp(parse[i],"ls")==0)
			{
				char argv[1001];
				getcwd(argv,sizeof(argv));
				if(i+1==j)
					ls(argv,0);
				else if(strcmp(parse[i+1],"-a")==0 && strcmp(parse[i+2],"\0")==0)
					ls(argv,2);
				else if(strcmp(parse[i+1],"-l")==0 && strcmp(parse[i+2],"\0")==0)
					ls(argv,1);
				else if(strcmp(parse[i+1],"-la")==0 || (strcmp(parse[i+1],"-al")==0))
					ls(argv,3);
				else if((strcmp(parse[i+1],"-l")==0 && strcmp(parse[i+2],"-a")==0) || (strcmp(parse[i+1],"-a")==0 && strcmp(parse[i+2],"-l")==0))
					ls(argv,3);
				else if(strcmp(parse[1],"\0")!=0)
				{
					char e[1001];
					for(l=0;l<1000;l++)
						e[l]='\0';
					strcpy(e,parse[1]);
					if(e[0]=='~')
					{
						strcpy(e,pre);
						long long temp=strlen(e);
						for(long long meh=1;meh<ar[1];meh++)
						{
							e[temp]=parse[1][meh];
							temp++;
						}
					}
					ls(e,0);
				}
				else
				{
					strcpy(argv,parse[i+1]);
					ls(argv,0);
				}
			}
			else if(strcmp(parse[i],"pwd")==0)
			{
				char argv[1001];
				for(i=0;i<1000;i++)
					argv[i]='\0';
				getcwd(argv,sizeof(argv));
				printf("%s\n",argv);
			}
			else if(strcmp(parse[i],"echo")==0)
			{
				if(parse[i+1][0]!='$')
					ech(t,pre);
				else
				{
					char dp[1000],du[1000];
					for(int i=0;i<1000;i++)
					{
						du[i]='\0';
						dp[i]='\0';
					}
					long long k=strlen(parse[i+1]);
					for(long long u=1;u<k;u++)
						dp[u-1]=parse[i+1][u];
					int gg=0,c=0;
					for(int j=0;j<cou;j++)
					{
						long long h=strlen(en[j]);
                                                for(long long k=0;k<h;k++)
                                                {
                                                         if(en[j][k]=='=')
                                                                 break;
                                                         du[gg]=en[j][k];
                                                         gg++;
                                                }
                                                if(strcmp(du,dp)==0)
                                                {
                                                         c++;
                                                         for(long long u=k;u<h;u++)
								 printf("%c",en[j][u]);
							 printf("\n");
                                                }
                                                for(int y=0;y<1000;y++)
                                                        du[y]='\0';
                                                gg=0;
					}
					if(c==0)
						printf("No variable Found\n");
				}
			}
			else if(strcmp(parse[i],"cd")==0)
			{
				char e[1001];
				for(l=0;l<1000;l++)
					e[l]='\0';
				if(strcmp(parse[1],"\0")==0)
					strcpy(e,"~");
				else
					strcpy(e,parse[1]);
				if(e[0]=='~')
				{
					strcpy(e,pre);
					long long temp=strlen(e);
					for(long long meh=1;meh<ar[1];meh++)
					{
						e[temp]=parse[1][meh];
						temp++;
					}
				}
				if(chdir(e)==0)
				{
				}
				else
					perror("failed");
			}
			else if(strcmp(parse[i],"overkill")==0)
			{
				for(long long int py=1;py<id;py++)
					kill(job[py],9);
			}
			else if(strcmp(parse[i],"jobs")==0)
				jobs();
			else if(strcmp("kjob",parse[i])==0)
			{
				if(strcmp(parse[i+2],"\0")==0)
					printf("Insufficient Arguments\n");
				else
					kill(job[atoi(parse[i+1])],atoi(parse[i+2]));
			}
			else if(strcmp("fg",parse[i])==0)
				fg();
			else if(strcmp("bg",parse[i])==0)
				bg();
			else
			{
				if(strcmp(parse[i],"cronjob")==0)
				{
					int st;
					pid_t v=fork();
					if(v==0)
					{
						pid_t y=fork();
						if(y!=0)
						{
							int sl=0;
							long long var1=((int)parse[j-3][0]-48),var2=((int)parse[j-1][0]-48);
							for(long long p=0;p<(var2/var1);p++)
							{
								dela(var1*1000);
								waitpid(y,&st,0);
							}
							exit(0);
						}
						else
						{
							char *args[]={parse[2]};
							long long h=3;
							for(h=3;h<j;h++)
							{
								if(parse[h][0]=='-' && parse[h][1]=='t')
									break;
								args[h-2]=parse[h];
							}
							args[h-2]=NULL;
							char dfo[1001];
							for(int i=0;i<1000;i++)
								dfo[i]='\0';
							strcpy(dfo,parse[2]);
							int sp;
							long long var1=((int)parse[j-3][0]-48),var2=((int)parse[j-1][0]-48);
							for(long long p=0;p<(var2/var1);p++)
							{
								dela(var1*1000);
								pid_t f=fork();
								if(f==0)
								{
									if(execvp(dfo,args) < 0)
										perror("Command not found");
									exit(0);
								}
								else
									waitpid(f,&sp,0);
							}
							exit(0);
						}
					}
					else
					{
					}
				}
				else if(strcmp(parse[i],"nightswatch")!=0)
				{
					long long h=0;
					pid_t a=fork();
					if(a!=0)
					{
						ppiidd=a;
						for(int u=0;u<1000;u++)
							varu[i]='\0';
						strcpy(varu,parse[i]);
						for(int o=1;o<j;o++)
						{
							strcat(varu," ");
							strcat(varu,parse[o]);
						}
						waitpid(a,NULL,WUNTRACED);
					}
					else
					{
						char *args[]={parse[i]};
						for(h=1;h<j;h++)
							args[h]=parse[h];
						args[h]=NULL;
						if(execvp(parse[i],args) < 0)
							perror("Command not found");
						exit(0);
					}
				}
			}
		}
		else
		{
			long long h=0;
			int state;
			pid_t a=fork();
			if(a==0)
			{
				pid_t b=fork();
				if(b==0)
				{
					setpgid(0,0);
					char *args[]={parse[i]};
					for(h=1;h<j-1;h++)
						args[h]=parse[h];
					args[h]=NULL;
					if(execvp(parse[i],args) < 0)
						perror("Command not found");
					exit(0);
				}
				else
				{
					waitpid(b,&state,0);
					if(WIFEXITED(state))
						printf("%s with pid %d exited normally\n",parse[i],b);
					else
						printf("%s with pid %d exited via signal %d\n",parse[i],b,WTERMSIG(state));
					exit(0);
				}
				exit(0);
			}
			else
			{
				job[id]=a+1;
				strcpy(name[id],parse[i]);
				for(int o=1;o<j-1;o++)
				{
					strcat(name[id]," ");
					strcat(name[id],parse[o]);
				}
				id++;
			}
		}
		for(i=0;i<j;i++)
		{
			long long k=strlen(parse[i]);
			for(l=0;l<k;l++)
				parse[i][l]='\0';
		}
		for(i=0;i<len;i++)
			t[i]='\0';
		for(i=0;i<j;i++)
			ar[i]=0;
		t = strtok(NULL,";");
	}
	clea(pre);
	return 1;
}
