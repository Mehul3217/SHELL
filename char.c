#include "header.h"

char gem()
{
        int r;
        unsigned char c;
        if ((r = read(0, &c, sizeof(c))) < 0)
                return 'c';
        else
                return c;
}
