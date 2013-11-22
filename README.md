quicksort
=========

This is a sample project for a quicksort interview project.  The project will
serve as a simple task to be completed as part of the interview process.  The
instructions are given below.

1. Create an open source project on github.  Add a README to the repository
containing:
    * A summary of the problem you are trying to solve
    * A description of your solution to the problem

2. Add a simple echo program written in C to the project that takes a binary
stream of unsigned integers as input and prints them to standard out. The
program should compile with GCC on a Linux system, it will be compiled with the
following flags:

    gcc -std=c99 -pedantic -Wall -Werror -Wextra -O0 -g -ggdb myecho.c -o myecho

The program will be executed on a Debian GNU/Linux system as follows:

    dd if=/dev/urandom bs=4 count=<n> | myecho

where <n> is the number of unsigned integers to be piped to stdin.

3. Add a program written in C to the project that provides a recursive
implementation of the quicksort algorithm. The program will take a binary
stream of unsigned integers as input and print them in sorted order to standard
out. The program should compile with GCC on a Linux system it will be compiled
with the following flags:

    gcc -std=c99 -pedantic -Wall -Werror -Wextra -O0 -g -ggdb mysort.c -o mysort

The program will be executed on a Debian GNU/Linux system as follows:

    dd if=/dev/urandom bs=4 count=<n> | mysort

where <n> is the number of unsigned integers to be piped to stdin.

4. Extra Credit: For a list of 256 integers we would expect on average to see
2048 iterations through the algorithm.  How many would we expect for lists of
size 2, 1024, 2048, and 65536?
