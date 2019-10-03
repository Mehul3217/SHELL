#include "header.h"

extern char arr[1000][1000];
extern long long idx,go;
extern long long job[1000],id;
void exe()
{
        int i,fd=open("historyfile", O_CREAT | O_WRONLY | O_TRUNC , 0777);
        char temp[1001];
        for(i=0;i<1000;i++)
                temp[i]='\0';
        for(i=go;i<idx;i++)
        {
                strcpy(temp,arr[i]);
                if(temp[strlen(arr[i])-1]!='\n')
                        strcat(temp,"\n");
                write(fd,temp,strlen(temp));
                int h=strlen(temp);
                for(int j=0;j<h;j++)
                        temp[j]='\0';
        }
}
