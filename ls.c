#include "header.h"

void perm(struct stat s)
{
        char perms[11];
        if(S_ISREG(s.st_mode)) perms[0]='-';
        else if(S_ISDIR(s.st_mode)) perms[0]='d';
        perms[1] = (s.st_mode & S_IRUSR) ? 'r':'-';
        perms[2] = (s.st_mode & S_IWUSR) ? 'w':'-';
        perms[3] = (s.st_mode & S_IXUSR) ? 'x':'-';
        perms[4] = (s.st_mode & S_IRGRP) ? 'r':'-';
        perms[5] = (s.st_mode & S_IWGRP) ? 'w':'-';
        perms[6] = (s.st_mode & S_IXGRP) ? 'x':'-';
        perms[7] = (s.st_mode & S_IROTH) ? 'r':'-';
        perms[8] = (s.st_mode & S_IWOTH) ? 'w':'-';
        perms[9] = (s.st_mode & S_IXOTH) ? 'x':'-';
        perms[10] = '\0';
        printf("%s",perms);
}


void ls(char arg[],int j)
{
        DIR *p;
        struct dirent *d;
        struct stat buf;
        struct utsname uts;
        char *usr=getenv("USER");
        struct group *grp=NULL;
	struct group gr;
	char buffer[2001];
	getgrnam_r(usr,&gr,buffer,2001,&grp);

        struct tm Time;
        char Date[300];
        p=opendir(arg);
        if(p==NULL)
        {
                perror("Cannot find directory");
                return;
        }
        while(d=readdir(p))
        {
                if(j==0)
                {
                        if(d->d_name[0]=='.')
                                continue;
                        printf("%s\n",d->d_name);
                }
                else if(j==1)
                {
                        if(d->d_name[0]=='.')
                                continue;
                        stat(d->d_name,&buf);
                        perm(buf);
                        printf(" %d",(int)buf.st_nlink);
                        printf(" %s",usr);
			struct group *gr=getgrgid(buf.st_gid);
                        printf(" %s",gr->gr_name);
                        printf(" %5d", (int)buf.st_size);
                        localtime_r(&buf.st_mtime, &Time);
                        strftime(Date, sizeof(Date), "%F %T", &Time);
                        printf(" %s %s\n", Date, d->d_name);
                }
                else if(j==2)
                        printf("%s\n",d->d_name);
                else if(j==3)
                {
                        stat(d->d_name,&buf);
                        perm(buf);
                        printf(" %d",(int)buf.st_nlink);
                        printf(" %s",usr);
                        printf(" %s",usr);
                        printf(" %5d", (int)buf.st_size);
                        localtime_r(&buf.st_mtime, &Time);
                        strftime(Date, sizeof(Date), "%F %T", &Time);
                        printf(" %s %s\n", Date, d->d_name);
                }
        }
        return;
}
