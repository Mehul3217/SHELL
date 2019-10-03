# SHELL

I have created a interactive user defined Shell in C.

# Instructions to run:
- Type "make" without quotes on terminal.
- Then type ./shell to run file.


# Features Implemented:

- All Commands work as they work on real Terminal.
- Current Working directory ismade as home directory.
- Commands that are implemented separately
	- clear (Clears the terminal on typing "clear" or "reset").
	- echo 
	- history 
	- ls
	- cd
	- exit
    - pinfo (prints pid,process status,virtual memory and executable path ofcurrent running process)
    - fg (brings a running or a stopped background job with given job
number to foreground)
    - bg (changes a stopped background job to a running background
job with given job number)
    - pwd 
    - jobs (shows list of all background processes)
    - kjob (gives signal to the process 
      Usage ->  kjob <job number> <signal>)
    - overkill  (kill all background processes)
    - cronjob (executes a particular command in fixed
time interval for a certain period
	Usage -> cronjob -c <command name> -t <time interval> -p <time period> )
    - Ctrl + C (Exits the foreground process (if any))
    - Up arrow key (If the ‘UP’ key is pressed ‘K’ time consecutively, the K​ th ​previous command is executed)
    - setenv (sets the environmet variables
    Usage -> setenv <environment vriable> [<value>])
    - unsetenv (unsets the environment variable (if present)
    Usage -> unsetenv <environment variable>)
    - nighswatch (It executes the command until the 'q'
key is pressed
	Usage -> 1. nightswatch -n <time interval in which to execute the command (periodically)> interrupt
		 2. nightswatch -n <time interval in which to execute the command (periodically)> dirty)
- Background processes are made with '&' at end of command
- Piping and redirection are also handled.

# Description of files:
- bg.c
	- bg
- clear.c
	- clear
- echo.c
 	- echo
- env.c
 	- setenv
 	- unsetenv
 - fg.c
 	- fg
 - jobs.c
 	- jobs
 - ls.c
 	- ls
 - pinfo.c
 	- pinfo
 - main.c
 	- main loop
 - piping.c
 	- implements piping
 - redirect.c
 	- implements redirection
 - prompt.c
 	- Command prompt
 - parse.c
 	- Parsing user input
 - kbhit.c
 	- To check if a key is pressed
 - input.c
 	- User input
 - hist1.c ,hist2.c,hist3.c
 	- history
 - header.h
 	- include all headers
 - night.c
 	- nighswatch 
