#include "header.h"

extern char parse[1000][1000];
void night()
{
	if(strcmp(parse[1],"\0")==0 || strcmp(parse[2],"\0")==0 || strcmp(parse[3],"\0")==0)
		printf("Error: Less arguments passed\n");
	else
	{
		if(strcmp("dirty",parse[3])==0)
		{
			int g=0;
			char ch;
			char strin[1001];
			for(g=0;g<1000;g++)
				strin[g]='\0';
			g=0;
			while(1)
			{
				if(kbhit())
				{
					ch=gem();
					if(ch=='q')
						break;
				}
				FILE * fp;
				char * line = NULL;
				ssize_t len;
				ssize_t read;
				fp = fopen("/proc/meminfo", "r");
				while ((read = getline(&line, &len, fp)) != -1)
				{
					g++;
					if(g==17)
					{
						strcpy(strin,line);
						break;
					}
				}
				long long leni=strlen(strin),m,n=0;
				char arg[4][20];
				for(g=0;g<4;g++)
				{
					for(int o=0;o<20;o++)
						arg[g][o]='\0';
				}
				int val=0;
				for(g=0;g<leni;g++)
				{
					m=0;
					while(strin[g]!=' ' && g<leni)
					{
						if(strin[g]=='\n')
						{ 
							g++;
							continue;
						}
						val++;
						arg[n][m]=strin[g];
						m++;
						g++;
					}
					if(val>0)
						n++;
					val=0;
				}
				n=0;
				printf("%s %s\n",arg[1],arg[2]);
				fflush(stdout);
				for(g=0;g<leni;g++)
					strin[g]='\0';
				sleep(atoi(parse[2]));
				g=0;
			}
		}
		else
		{
			int g=0;
			char ch;
			char strin[1001];
			for(g=0;g<1000;g++)
				strin[g]='\0';
			g=0;
			int cou=0;
			while(1)
			{
				if(kbhit())
				{
					ch=gem();
					if(ch=='q')
						break;
				}
				FILE * fp;
				char * line = NULL;
				ssize_t len;
				ssize_t read;
				fp = fopen("/proc/interrupts", "r");
				while ((read = getline(&line, &len, fp)) != -1)
				{
					g++;
					if(g==3)
					{
						strcpy(strin,line);
						break;
					}
				}
				long long leni=strlen(strin),m,n=0;
				char arg[20][20];
				for(g=0;g<20;g++)
				{
					for(int o=0;o<20;o++)
						arg[g][o]='\0';
				}
				int val=0;
				for(g=0;g<leni;g++)
				{
					m=0;
					while(strin[g]!=' ' && g<leni)
					{
						if(strin[g]=='\n')
						{
							g++;
							continue;
						}
						val++;
						arg[n][m]=strin[g];
						m++;
						g++;
					}
					if(val>0)
						n++;
					val=0;
				}
				n=0;
				if(cou==0)
				{
					printf("CPU0    CPU1    CPU2    CPU3    CPU4    CPU5    CPU6    CPU7\n");
					cou++;
				}
				for(int i=1;i<=8;i++)
					printf("%s \t",arg[i]);
				fflush(stdout);
				printf("\n");
				for(g=0;g<leni;g++)
					strin[g]='\0';
				sleep(atoi(parse[2]));
			}
		}
	}
}
