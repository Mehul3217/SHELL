#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<sys/utsname.h>
#include<limits.h>
#include<string.h>
#include<dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <fcntl.h>
#include<libgen.h>
#include<signal.h>
#define _GNUSOURCE
#include<termios.h>
#include "prompt.h"
#include "pinfo.h"
#include "parse.h"
#include "char.h"
#include "clear.h"
#include "echo.h"
#include "hist1.h"
#include "hist2.h"
#include "hist3.h"
#include "input.h"
#include "kbhit.h"
#include "ls.h"
#include "redirect.h"
#include "piping.h"
#include<time.h>
#include "env.h"
#include "jobs.h"
#include "fg.h"
#include "bg.h"
#include "night.h"
