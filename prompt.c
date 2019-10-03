#include "header.h"

void prompt(char pre[])
{
        struct utsname uts;
        char *usr = getenv("USER");
        char *var=uts.version;
        int ret=uname(&uts);
        int i=4,j=0;
        char s[1001];
        while(var[i]!=' ')
        {
                s[j]=var[i];
                j++;
                i++;
        }
        printf("<%s@%s%s> ",usr,uts.sysname,pre);
}
