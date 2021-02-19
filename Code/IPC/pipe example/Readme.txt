There are three files in this directory. They illustrate the use of fork(),
exec(), and pipe() system calls.

The program in master.c creates two processes that execute the programs in
executable files `sqr' and `cube'.  The master process communicates integer
numbers 0-99 to sqr and cube processes via pipes. The master process
prints whole number 0-99 in a file called `whole_num'. The sqr process prints
the square of the number received from the master process in a file called
`squares'. The cube process prints the cube of the number received from the
master process in a file called `cubes'.

Compile by typing make

run master

