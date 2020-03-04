#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <time.h>

int main (int argc, char *argv[]){
	
	srand (time(NULL));
	/*
	 * Exo 5.1 création d'un simple processus
	 * 
	 * 
	int valRetun;
	int pid = fork();
	if (pid == 0){
		printf ("hello world fils:  Mon PID %d, celui de mon père %d\n", getpid(), getppid());
		int n = rand()%50;
		printf ("nombre aléatoire dans fils: %d\n",n);
		exit (n);
	}else{
		printf("Hello world Père:  mon PID %d celui de mon fils %d\n",getpid(), pid);	
	}
	wait(&valRetun);
	printf ("Nombre aléa dans pere %d %d \n", WEXITSTATUS (valRetun));
	*/
	
	/*
	
	//*****************************
	// Exo 5.2 sleep() & wait ()
	int retVal;
	int i = 1;
	int pid ;
	while (i<=10){
		int n = rand ()%10; 
		pid = fork();
		if (pid == 0){
			sleep (n);
			// printf ("Mon PID est %d et j'ai attendu %d secondes\n", getpid(), n);
			exit (n);
		}
		i++;
	}
	while ( (pid = wait (&retVal)) != -1)
		printf ("PID qui vient de se terminer %d il a attendu %ds\n", pid, WEXITSTATUS(retVal) );
	
	
	*/
	
	
	//*************************************
	// Exo 5.3 Création multiple de processus 
	
	if (argc != 3) return;
	
	int i=0;
	int j = 0;
	
	int n = atoi (argv[1]);
	int m = atoi (argv[2]);
	
	//***** 5-creer n fois m processus
	//~ while (i < n*m){
		 //~ if ( fork() ==0){ 
			 //~ i++; 
		//~ }
		//~ else { 
			//~ exit (0); 
		//~ }	
	//~ }
	//~ printf ("%d processus ont été créés\n", i); 
	
	//******6-Le processus pere cree m processus fils, puis chaque processus fils cr´ee n processus petit-fils.
	while (i<m){
		if (fork () == 0){
			while (j<n){
				if (fork () ==0){
					exit (0);
					
				}
				else {
					j++;
				}
			}
				j = 0;
				while (j < n)
					wait (NULL);
				exit (0);
		}else{
		}
	}
	
	i = 0;
		while (i<m){
wait (NULL);
}
	printf ("%d %d\n", i, j);
  return 0;
}
