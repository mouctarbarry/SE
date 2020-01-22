#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

pid_t create_process (){
	pid_t pid;
	do {
		pid = fork();
	} while ((pid == -1) && (errno == EAGAIN));
return pid;
}
void child_process(){
	printf("Im the child :\nmy PID is %d and my PPID is %d\n", (int) getpid(), (int) getppid());
}

void father_process (pid_t child_pid){
	printf("Im the father :\nmy PID is %d and my son's is %d \n", (int) getpid(), (int)child_pid);
}

int main(int argc, char const *argv[])
{
	
	pid_t  pid 	= create_process ();
	switch (pid){
		case -1: 
	perror ("fork");
	return EXIT_FAILURE;
	break;
	case 0: 
	child_process();
	break;
	default : 
	father_process (pid);
	break;
	}
	
	return 0;
}