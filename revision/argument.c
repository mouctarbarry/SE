#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

pid_t creat_process (){
  pid_t p;
	do{
		p = fork();
	}while (p == -1 && errno == EAGAIN);
return p;
}


void child_process (char *arg[]){
	if ( execv ("/usr/bin/baobab", arg) == -1)
	{
		perror ("execv");
		exit(EXIT_FAILURE) ;
	}
}
void father_process (){
	printf("Si ce message s'affiche ce que tout va bien :)\n");
}

int main(int argc, char *argv[])
{	//if (argc<2) return EXIT_FAILURE;
	char * arg[] = {"baobab", argv[1], NULL};
	
	pid_t pid = creat_process ();
	switch (pid){
		case 0: 
		child_process (arg);
		break;
		case -1: 
		perror("fork");
		return EXIT_FAILURE;
		break;
		default:
		father_process();
		break;
	}
return EXIT_SUCCESS;
}
