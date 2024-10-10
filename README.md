gcc -c main.c -o main.o
gcc -c library.c -o library.o
gcc -c file.c -o file.o
gcc -o my_program main.o library.o file.o
./my_program
