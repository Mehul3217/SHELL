#include "header.h"

extern char arr[1000][1000];
extern long long idx,go;
void add(char k[])
{
        strcpy(arr[idx],k);
        idx++;
        if(idx>20)
                go++;
}
