#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "io_file.h"

// Affichage du contenu d'un fichier
// \param	path			Nom/chemin du fichier à afficher
// \return					-1 si échec à l'ouverture, 0 sinon
int print(const char *path) {  }
// Copie de fichier
// \param	path1			Nom/chemin du fichier source
// \param	path2			Nom/chemin du fichier destination
// \return					-1 si échec à l'ouverture, 0 sinon
int copy(const char *path1, const char *path2) {  }
// Déplacement de fichier
// \param	path1			Nom/chemin du fichier source
// \param	path2			Nom/chemin du fichier destination
// \return					-1 si échec à l'ouverture, 0 sinon
int move(const char *path1, const char *path2) {  }
// Comparaison entre deux fichiers
// \param	path1			Nom/chemin du premier fichier
// \param	path2			Nom/chemin du second fichier
// \return					-1 si échec à l'ouverture,
//							1 si fichiers identiques, 0 sinon
int are_the_same(const char *path1, const char *path2) {  }

void check_print() {
	int nstdout = creat("test2.txt", 0644);
	int tmp, tmp2;

	system("echo 'This file\nis\n\nGREAT!\n' >test1.txt");

	tmp = dup(fileno(stdout));

	// Vider (entre autre) le buffer de stdout
	fflush(NULL);
	dup2(nstdout, fileno(stdout));

	print("test1.txt");

	// Vider (entre autre) le buffer de stdout
	fflush(NULL);
	dup2(tmp, fileno(stdout));

	close(nstdout); close(tmp);

	if (!system("diff test1.txt test2.txt >diff.log"))
		printf("'print()' test has succeeded.\n");
	else
		printf("'print()' test has failed.\n");

	system("rm -f diff.log test1.txt test2.txt");
}

void check_copy() {
	system("echo 'This file\nis\n\nGREAT!\n' >test1.txt");

	copy("test1.txt", "test2.txt");

	if (!system("diff test1.txt test2.txt >diff.log"))
		printf("'copy()' test has succeeded.\n");
	else
		printf("'copy()' test has failed.\n");

	system("rm -f diff.log test1.txt test2.txt");
}

void check_move() {
	system("echo 'This file\nis\n\nGREAT!\n' >test1.txt");
	system("cat test1.txt >test2.txt");

	move("test2.txt", "test3.txt");

	if (!system("test -e test2.txt") )
		printf("'move() test has failed.\n");
	else if (!system("diff test1.txt test3.txt >diff.log"))
		printf("'move()' test has succeeded.\n");
	else
		printf("'move()' test has failed.\n");

	system("rm -f diff.log test1.txt test3.txt");
}

void check_are_the_same () {
	system("echo 'This file\nis\n\nGREAT!\n' >test1.txt");
	system("echo 'This file\nis\n\nGREAT!\n' >test2.txt");
	system("echo 'This file\nis\n\nGREAT!\n\n' >test3.txt");
	system("echo 'This fil\nis\n\nGREAT!\n' >test4.txt");
	system("echo 'This file\nis\nGREAT!\n' >test5.txt");

	if (!are_the_same("test1.txt", "test2.txt"))
		printf("'are_the_same()' test#1 has failed.\n");
	else if (are_the_same("test1.txt", "test3.txt"))
		printf("'are_the_same()' test#2 has failed.\n");
	else if (are_the_same("test2.txt", "test4.txt"))
		printf("'are_the_same()' test#3 has failed.\n");
	else if (are_the_same("test3.txt", "test5.txt"))
		printf("'are_the_same()' test#4 has failed.\n");
	else
		printf("'are_the_same()' test has succeeded.\n");

	system("rm -f test1.txt test2.txt test3.txt test4.txt test5.txt");
}

int main(int argc, char **argv) {
	check_print();
	check_copy();
	check_move();
	check_are_the_same();

	return 0;
}
