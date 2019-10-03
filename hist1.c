#include "header.h"

extern char arr[1000][1000];
extern long long idx,go;
void hist(int num)
{
        int i;
        if(num==0 || num>10)
        {
                int c=0;
                for(i=idx-1;i>=go;i--)
                {
                        if(arr[i][strlen(arr[i])-1]!='\n')
                                printf("%s\n",arr[i]);
                        else
                                printf("%s",arr[i]);
                        c++;
                        if(c==10)
                                break;
                }
        }
        else
        {
                int c=0;
                for(i=idx-1;i>=go;i--)
                {
                        if(arr[i][strlen(arr[i])-1]!='\n')
                                printf("%s\n",arr[i]);
                        else
                                printf("%s",arr[i]);
                        c++;
                        if(c==num)
                                break;
                }
        }
}
