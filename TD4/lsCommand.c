#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>


//écrire une fonction qui a le même comportement que la commande ls
// 1: affichage du type du fichier

void afficheType (char *nomFic){
	
	struct stat sb;
	
           if (stat(nomFic, &sb) == -1) {
               printf ("l'appel à stat n'a pas fonctionner");
               exit(-1);
           }

           printf("Type de fichier : ");

           switch (sb.st_mode & S_IFMT) {
           case S_IFBLK:  printf("périphérique (Device) bloc\n");       break;
           case S_IFCHR:  printf("périphérique caractère\n");  			break;
           case S_IFDIR:  printf("répertoire\n");             			break;
           case S_IFIFO:  printf("FIFO/tube\n");             			break;
           case S_IFLNK:  printf("lien symbolique\n");         			break;
           case S_IFREG:  printf("fichier regulier\n");        			break;
           case S_IFSOCK: printf("socket\n");                 			break;
           default:       printf("inconnu ?\n");             			break;
           }
	
}


int main (int argc, char *argv[]){
	// teste les arguments
	afficheType (argv[1]);
			
}
