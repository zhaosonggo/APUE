
%:%.c ../lib/libapue.so
	gcc -o $@ $< -L../lib -lapue -I../inc
		
../lib/libapue.so: ../src/apue.o
	gcc -shared -o ../lib/libapue.so ../src/apue.o

../src/apue.o:../src/apue.c
	gcc -fPIC -o ../src/apue.o -c ../src/apue.c -I../inc

