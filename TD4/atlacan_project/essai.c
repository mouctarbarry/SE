#include <stdio.h>
#include "atlacan.h"
#include <stdbool.h>
#include <string.h>

typedef struct chemin CHEMIN;
struct chemin {
	char ** tabChemins;
	int indiceLocal[2];
};

int main (int argc, char *argv[]){
	
	if (atl_init ()==0)	printf ("\n\n	INITIALISATION RÉUSSIT	\n\n");
		 
		
	atl_fini();	
return 0;
}

void recherche_Atlacan(const char **path, int indiceTresore){
	if (indiceTresore == 0) return;
	
	int nbElem; 
	int nbChemins = 0;
	CHEMIN ch;
	ch.tabChemins;
	ch.tabChemins = malloc (20*sizeof (char*));
	
	atl_ls (&path, &nbElem);
	struct atl_stat *fic;
	
	atl_stat(path[i], fic);
	fic = malloc (nbElem*sizeof (struct atl_stat));
	
	for (int i = 0; i<nbElem; i++){
		//si c'est un bon chemin
		if (atl_is_dir(fic->mode) && fic->uid != UID_CLAYTON &&  atl_is_oxmode(fic->mode) ){
					
					nb.tabChemins[nbChemins] = (path[i]);
					nbChemins++;
		}
		if (atl_is_file(fic->mode) && fic->gid != GID_PERTONTAN && fic->gid ==GID_ABITHAN){
			
				//si c'est un bon lieu
					atl_cat (path[i], &indiceTresore);
		}
		ch.indiceLocal[0] = indiceTresore;
		//on libere ls
		atl_free_ls (path); 
		char * cheminAbsolu = malloc (20*sizeof(char) );
		
		//on recupere le bon chemin
		for (int i=0; i<nbChemins; i++){
				
		}
		
		
		
		
	} 
	
	
}

int recupIndiceLocal (){}
