#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	const char * a = "Add jour";
	char * action = malloc (30*sizeof (char));
	char * word = malloc (30*sizeof (char));
	int i = 0;
	while (a[i] != ' '){
		action [i] = (a[i]);
		i++;
	}
	int j = 0;
	i = i+1;
	while (a[i] != '\n'){
		word [j] = a[i];
		i++;
		j++;
	}
	printf ("%s %s\n", action, word);
}
