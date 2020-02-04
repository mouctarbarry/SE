run: test
	./exec
test: test_lexc.c lexc.c
	gcc -DTEST_LEXC -Wall -o exec test_lexc.c lexc.c -g
clean: 
	rm exec
	
