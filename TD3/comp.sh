gcc -c -fPIC io_file.c
ar rcs libiof.a io_file.o
gcc main.c -L. -liof

