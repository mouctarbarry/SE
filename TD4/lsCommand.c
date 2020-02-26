#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <pwd.h>
#include <dirent.h>




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

void affichePermission (char *nomFic){
	struct stat sb;
	if (stat(nomFic, &sb) == -1) {
              printf ("l'appel à stat n'a pas fonctionner");
              exit(-1);
       }
       
     printf ("les droits :");
     
     
		//if (sb.st_mode & S_ISUID) 
		 if (sb.st_mode & S_IRUSR){
			 printf ("r");
		 }
		 else printf ("-");
		 if (sb.st_mode & S_IWUSR){
			 printf ("w");
		 }
		 else printf ("-");
		 if (sb.st_mode & S_IXUSR){
			 printf ("x");
		 }
		 else printf ("-");
		 
		 if (sb.st_mode & S_IRGRP){
			 printf ("r");
		 } else printf ("-");
		 if (sb.st_mode & S_IWGRP){
			 printf ("w");
		 } else printf ("-");
		 if (sb.st_mode & S_IXGRP){
			 printf ("x");
		 } else printf ("-");
		 
		 if (sb.st_mode & S_IROTH){
			 printf ("r");
		 } else printf ("-");
		 if (sb.st_mode & S_IWOTH){
			 printf ("w");
		 } else printf ("-");
		 if (sb.st_mode & S_IXOTH){
			 printf ("x");
		 } else printf ("-");
		 printf ("\n");
}

void afficheUser (char *nomFic){
	struct stat sb;
	if (stat(nomFic, &sb) == -1) {
              printf ("l'appel à stat n'a pas fonctionner");
              exit(-1);
       }
	
	struct passwd * pw; 
	pw = getpwuid(sb.st_uid);
	printf ("Nom utilisateur : %s \n", pw->pw_name);
	printf ("Repertoire du fichier: %s \n", pw->pw_dir);
	
}

void afficheTaille (char *nomFic){
	struct stat sb;
	if (stat(nomFic, &sb) == -1) {
              printf ("l'appel à stat n'a pas fonctionner");
              exit(-1);
       }
          
    printf ("Taille du fichier %ld octets\n", (long)sb.st_size);  
}

void afficheRep (char *nomRep){
	DIR *rep;
	rep = opendir (nomRep);
	struct dirent * sdir; 
	while ((sdir = readdir (rep) )!= NULL){
		printf ("%s\n\n", sdir->d_name);
		char tabChar[1024];
		printf ("Fichier : %s \n", sdir->d_name);
		sprintf (tabChar, "%s/%s", nomRep, sdir->d_name);
		afficheType (tabChar);
		affichePermission (tabChar);
		afficheUser (tabChar);
		afficheTaille (tabChar);
	}
}

int main (int argc, char *argv[]){
	if (argc != 2){
		printf ("problème d'arguments à l'execution\n");
		exit (-1);
	}
	printf ("\nFichier : %s\n\n", argv[1]);
	
	afficheType (argv[1]);
	affichePermission (argv[1]);
	afficheUser (argv[1]);
	afficheTaille (argv[1]); 
	
	afficheRep (".");
			
}
