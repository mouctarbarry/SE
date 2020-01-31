#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACTION_SIZE 16
#define WORD_SIZE   48

/**
 * Defines a lexicon.
 */
struct lexc {
	char **mots;
	int nb_mots;
	char * nom_lex;
	int isMutable;
};

/**
 * Initializes a lexicon data structure.
 * 
 * The lexicon must be freed using the lexc_fini() function.
 *
 * @param[in]  name             Lexicon name.
 * @param[in]  mutable          TRUE if the lexicon is mutable.
 *
 * @return     New lexicon.
 */
struct lexc *lexc_init(const char *name, const int mutable)
{
	struct lexc *lex;
	lex = malloc (sizeof (struct lexc));
	lex->isMutable = mutable;
	lex->mots = NULL;
	lex->nom_lex = strdup (name);
	lex->nb_mots = 0;
    return lex;
}

/**
 * Releases a lexicon data structure.
 *
 * @param      lexc             Lexicon to release.
 */
void lexc_fini(struct lexc *lex)
{
	if (lex != NULL && lex->mots != NULL){
		for (int i = 0; i<lex->nb_mots; i++){
			free (lex->mots[i]);
		}
	free (lex->mots);
	free (lex);
	}
}

int lexc_check(struct lexc *lex, const char *word)
{
	if (lex != NULL && word != NULL && lex->mots !=NULL){
		for (int i = 0; i<lex->nb_mots; i++){
			if (strcmp (lex->mots[i], word)==0)
				return 0;
		}
	}
  return 1;
}

int lexc_add(struct lexc *lex, const char *word)
{
	if (lex != NULL && (lex->isMutable==1) && word != NULL && lexc_check (lex, word)==1){
		
		lex->mots = realloc (lex->mots, (lex->nb_mots+1)*sizeof(char *) );
		lex->mots[lex->nb_mots] = strdup(word);
		lex->nb_mots++;
		return 0;
	}
    else return 1;
}

int lexc_remove(struct lexc *lex, const char *word)
{
	if (lex != NULL && (lex->isMutable==1) && word != NULL && lexc_check (lex, word)==0){
		int indice;
		for (int i= 0; i<lex->nb_mots; i++){
			if (strcmp (lex->mots[i], word)==0){
				free (lex->mots[i]);
				indice = i;
			}
		}
		for (int i = indice; i<lex->nb_mots-1; i++){
			lex->mots[i] = lex->mots[i+1];
		}	
		lex->mots = realloc(lex->mots, (lex->nb_mots-1)*sizeof (char *));
		lex->nb_mots--;
		return 0;
	}
   else return 1;
}

void print_lexc(struct lexc *lex){
	if (lex != NULL && lex->mots != NULL){
		printf ("-----Liste des mots du lexique-----\n");
		for (int i = 0; i<lex->nb_mots; i++){
			printf ("%s\n", lex->mots[i]);
		}
	}
	else printf ("impossible d'afficher un lexique vide\n");
}


int cmd_interpret(struct lexc *lex, const char *cmd)
{	
	char * action = malloc (30*sizeof (char));
	char * word = malloc (30*sizeof (char));
	int i = 0;
	while (cmd[i] != ' ' || cmd[i] == '\n'){
		action [i] = (cmd[i]);
		i++;
	}
	if (cmd[i-1] == '\n' &&  (strcmp(action, "quit") == 1 || strcmp(action ,"print") == 1 ) ){
		printf ("Mauvaise commande");
		return 0;
	}
	int j = 0;
	i = i+1;
	while (cmd[i] != '\n'){
		word [j] = cmd[i];
		i++;
		j++;
	}
	
		if ( strcmp ( action,"find") == 0 ){
			int res=1;
			res = lexc_check (lex, word);
			printf ( (res==0) ? "Mot trouvé\n" : "Mot non trouvé\n");
			return 1;
		} 
		else if (strcmp (action, "add") == 0){
			int res=1;
			res = lexc_add (lex, word);
			printf ( (res==0) ? "Mot ajouté\n" : "Mot non ajouté\n");
			return 1;
		}
		else if (strcmp (action, "remove") == 0){
			int res=1;
			res = lexc_remove (lex, word);
			printf ( (res==0) ? "Mot retiré\n" : "echec\n");	
			return 1;
		}
		else if (strcmp (action, "print") == 0){
			print_lexc (lex);
			return 1;
		}
		else if (strcmp (action, "quit") == 0) { printf ("Fin du programme\n"); return 0;}
		else { printf ("Commande inconne, sortie\n"); return 0; }
}


int main(){
	char buffer[65];
	struct lexc *L;

	L = lexc_init("test", 1);

	do {
		fgets(buffer, 65, stdin);
	} while (cmd_interpret(L, buffer));
	lexc_fini(L);
	
	
return 0;
}














