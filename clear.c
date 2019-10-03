#include "header.h"

void clea(char *pre)
{
        char pro[1001];
        char try[1001];
        long long i;
        for(i=0;i<1000;i++)
        {
                try[i]='\0';
                pro[i]='\0';
        }
        getcwd(pro,sizeof(pro));
        if(strlen(pro)<strlen(pre))
                prompt(pro);
        else
        {
                strcpy(try,"~");
                long long l=1;
                i=0;
                while(pro[i]==pre[i])
                        i++;
                long long h=strlen(pro);
                while(i<h)
                {
                        try[l]=pro[i];
                        i++;
                        l++;
                }
                prompt(try);
        }
}
