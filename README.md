asgn0 folder contains the following files:

mycat.c

makefile

readme.txt

design.txt


With the makefile and mycat.c in the same folder enter in the command line:

make

This will build the project.

To run the program type

./mycat filename1 filename2

mycat works like the regular cat program and can be used with commands such as 

< > and | grep string1

example

./mycat file1 > file1_copy

./mycat file | grep string
