#include "header.h"

extern char str[100010];
extern char stm[100001];
int input(char *pre)
{
        char c,d;
        long long i;
        int p=scanf("%c",&c);
	if(p==EOF)
		return -1;
        if(c=='\n')
        {
                char y[1001],try[1001];
                for(i=0;i<1000;i++)
                {
                        y[i]='\0';
                        try[i]='\0';
                }
                getcwd(y,sizeof(y));
                if(strlen(y)<strlen(pre))
                        prompt(y);
                else
                {
                        strcpy(try,"~");
                        long long l=1;
                        i=0;
                        while(y[i]==pre[i])
                                i++;
                        long long h=strlen(y);
                        while(i<h)
                        {
                                try[l]=y[i];
                                i++;
                                l++;
                        }
                        prompt(try);
                }
                for(i=0;i<sizeof(str);i++)
                        str[i]='\0';
                return -1;
        }
	for(i=0;i<100000;i++)
		stm[i]='\0';
        scanf("%[^\n]s",stm);
        scanf("%c",&d);
        str[0]=c;
        strcat(str,stm);
        return 0;
}
