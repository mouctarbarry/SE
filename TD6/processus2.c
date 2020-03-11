#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <time.h>

int main (int argc, char *argv[]){
					// exo 6.1 Execution de commande
							// 1.)
							//~ char * arg [] = {"ps", NULL};
							//~ if (fork() == 0){
								
								//~ if (execv ("/bin/", arg) == -1){
									//~ perror ("execv");
									//~ return EXIT_FAILURE;
								//~ }
								//~ exit (0);
							//~ }
							//~ wait (NULL);
							
							// 2.)
							//~ char * arg [] = {"ls", argv[1], NULL};
							//~ if (fork() == 0){
								
								//~ if (execv ("/bin/ls", arg) == -1){
									//~ perror ("execv");
									//~ return EXIT_FAILURE;
								//~ }
								//~ exit (0);
							//~ }
							//~ wait (NULL);
							
			
	
							//~ // 3.)
							//~ if (fork() == 0){
								//~ char * arg1 [] = {"find", argv[1], "-type", "f", NULL};
								//~ printf ("Liste des fichiers reguliers dans ~\n");		
								//~ if (execv ("/usr/bin/find", arg1) == -1){
									//~ perror ("execv");
									//~ return EXIT_FAILURE;
							//~ }
							//~ exit (0);
							//~ }
						//~ wait (NULL);
						//~ if (fork() == 0){
								//~ char * arg2 [] = {"find", argv[1], "-type", "d", NULL};
								//~ printf ("Liste des fichiers dossiers dans ~\n");		
								//~ if (execv ("/usr/bin/find", arg2) == -1){
									//~ perror ("execv");
									//~ return EXIT_FAILURE;
							//~ }
							//~ exit (0);
						//~ }
						//~ wait(NULL);
						
		
		
		
									//~ // Exo 6.2     	
									 //~ sysconf(_SC_CLK_TCK);

									//~ char * arg [] = {"times", NULL};

									//~ if (fork() == 0){
										//~ for (int i = 0; i<5; i++)
											//~ system ("ls");
										//~ exit (0);
									//~ }
									//~ int pid_fils = wait (NULL);
									//~ struct tms *buf;
									//~ times (buf);
									//~ printf ("%d %d \n", buf->tms_cutime, buf->tms_cutime );
										
										
		
		
	// Exo 6.3 kill () SIGINT SIGSTOP
	pid_t pid;
	if (  (pid = fork()) == 0){
		for (int i=1; i<=5; i++){			
			sleep(1);
			printf("%d\n", i);
		}
		exit (0);
	}
	
	sleep (3);
	kill (pid, SIGSTOP);
	sleep (5);
	kill (pid, SIGCONT);
	
	wait(NULL);
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
}
