
gcc -g -o prog mystery-code.c

if [ "$1" = "release" ] 
then
	./prog 
elif [ "$1" = "debug" ]
then 
	gdb ./prog
else
 echo "ss"
fi
