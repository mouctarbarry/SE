#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


#include "io_file.h"

IO_FILE IO_open(const char *path, int access){
	IO_FILE fic;
	fic.desc = -1;
	if (path == NULL) return fic;
	
	int fd = -1;
	fd = open (path, O_CREAT | access);
	if (fd == -1) return fic;

	fic.desc = fd;
	fic.path = strdup(path);
	fic.access = access;
	return fic;
}
int IO_close (IO_FILE file){
	if (file.desc == -1) return -1;
	if (file.path != NULL)
	free (file.path);
	return close (file.desc);
}

int IO_remove(const char *path){
	if (path != NULL) 
		return remove (path);
}

int IO_char_read(IO_FILE file, char *c){
	int fd = -1;
	if (file.desc == -1) return fd;
	if (file.access == O_RDONLY || (file.access & O_RDWR) > 0) {
		fd = read (file.desc, c, sizeof (char) );
	}
	return fd;
}

int IO_char_write(IO_FILE file, const char c){
	int fd = -1;
	if (file.desc == -1 || file.path == NULL) return fd;
	if (file.access == O_WRONLY || (file.access & O_RDWR) > 0) {
		fd = write (file.desc, &c, sizeof (char));
	}
	return fd;
}







