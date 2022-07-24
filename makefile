all:
	gcc -c lib.c -o lib.o
	ar rcs lib.a lib.o
	gcc -c final.c -o final.o
	gcc -o final final.o -L. lib.a
