# -*- Makefile -*-



all:
	gcc -g redirect.c jobs.c fg.c bg.c night.c env.c piping.c char.c  clear.c  echo.c  hist1.c  hist2.c  hist3.c  input.c  kbhit.c  ls.c  main.c  parse.c  pinfo.c  prompt.c  -o shell
