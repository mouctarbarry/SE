#include <stdio.h>
#include "atlacan.h"
#include <stdbool.h>
#include <string.h>

int recupIndiceLocal (const char * path_name){
			
			char * pathcd = malloc (sizeof (char));
			pathcd = strdup (path_name);
			
			int a = atl_cd(path_name);
			
			if (a==0)
				printf ("\ndeplacement vers -> %s réussi\n", pathcd);
			
			struct atl_stat *fic;
			char **path;
			path = malloc (20*sizeof (char *) );
			int nbElem;
			int indiceTresor;
			
			int indicelocal;
			
			atl_ls (&path, &nbElem);
			
			fic = malloc (nbElem*sizeof (struct atl_stat));
			
			for (int i = 0; i<nbElem; i++){
				
				atl_stat(path[i], fic);
				
				if (atl_is_file(fic->mode) && fic->gid != GID_PERTONTAN && fic->gid ==GID_ABITHAN){
					
					atl_cat (path[i], &indiceTresor);
					indicelocal = indiceTresor;
				}
			}
			free (fic);
			free (pathcd);
			atl_free_ls (path, nbElem);
	return indicelocal;
}



char * recupChemin (const char ** chemins, int cptChemin, int valindice){
		
		// chemins contient un nombre de chemins valable on veut voir quels est le bon
		// dans recupChemin on se deplace dans un premier dossier 
		// on verifie que 
		// si c'est le bon on le retourne avec getpwd ()
		// sinon on revient en arrière
		
		int indiceLocal;
		
		// = malloc (20* sizeof (char));
		
		for (int i =0; i<cptChemin; i++){
			
			// int a = atl_cd (chemins[i]);
			//	printf ("deplacement dans recupChemin %d\n", 0);
			indiceLocal =  recupIndiceLocal (chemins[i]);
			
			if (indiceLocal < valindice){
				return strdup (atl_getpwd());
			}
			else atl_cd ("..");
		}			
}


int main (int argc, char *argv[]){
	
	if (atl_init ()==0)	printf ("\n\n	INITIALISATION RÉUSSIT	\n\n");
		 
		int indiceTresor;
		do{
			struct atl_stat *fic;
			char **path; 
			path = malloc (sizeof (char *) );
			int nbElem;
			//int indiceTresor;
			
			int cptChemin=0;
			int cptFic =0;
			
			atl_ls (&path, &nbElem);
			
			const char ** chemins = malloc (30*sizeof(char *));
			int valindice;
			
			int x = 0;
			
			for (int i = 0; i<nbElem; i++){
				
				fic = malloc (nbElem*sizeof (struct atl_stat));
				atl_stat(path[i], fic);
				
				if (atl_is_dir(fic->mode) && fic->uid != UID_CLAYTON 
						&&  atl_is_oxmode(fic->mode) &&  atl_is_ormode(fic->mode) &&  atl_is_owmode(fic->mode) ){
					
					cptChemin++;
					chemins[x] = strdup (path[i]);
					x++;
				}
				if (atl_is_file(fic->mode) && fic->gid != GID_PERTONTAN && fic->gid ==GID_ABITHAN){
					
					cptFic ++;
					atl_cat (path[i], &indiceTresor);
					valindice = indiceTresor;
					
				}
			}
			
			free (fic);
			
			printf ("\nOn est dans %s\n", strdup (atl_getpwd() ));
			//printf ("Chemin à prendre %s il y'en a %d', indice lieux restants %d et y'a %d fic\n", chemin, cptChemin,
				//				indiceTresor, cptFic); 

				
				char *s = strdup (recupChemin(chemins, cptChemin, valindice));
				atl_cd(s);
				
				printf("\nOn est dans %s\n ", s);
			
			//printf ("%s\n", recupChemin(chemins, cptChemin, valindice) );
			
			
								
	} while (indiceTresor>0);
			
				
		
atl_fini();	
return 0;
}
