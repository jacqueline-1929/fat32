Project Summary:
This code provides a FAT32 file system with the following functions implemented and working properly: 

	1.	Close 	(cmd: close <FILE>)
	2.	Create 	(cmd: create <FILE>)
	3.	Open 	 (cmd: open <FILE> <r/w/rw>)
	4.	Read 	(cmd: read <FILE> <startnum> <num_bytes>)
	5.	Change Directory	(cmd: cd <DIR>)
	6.	List 		(cmd: ls)
	7.	Size 	(cmd: size <FILE>)

The following functions  are unimplemented/faulty:

	1.	Make Directory 	(cmd: mkdir <DIR>)
	2.	Undelete  	(cmd: undelete)
	3.	Remove Directory 	(cmd: rmdir <DIR>)
	4.	Write 	(cmd: write <FILE> <startnum> <data> )
	5.	Remove	 (cmd: rm <FILE>)
The source code is implemented in C++ and a makefile is included.

File Summary:

The following files were created for project 3:
	1.	README.txt 
		a.	This file!
	2.	Report.txt 
		a.	Summary of project creation and implementation.

In the /src directory:
	1.	utils.h
	2.	client.cpp
	3.	makefile

Building the program:
	1.	change to src directory
	2.	make

Running the program:
	1.	./client fat32.img

General Information:

Client.cpp has the majority of the logic. There are no other cpp files, only the utils.h files, which is included in the client.cpp file. Const is used often as a precautionary measure. Much of the logic is implemented using if statements, and there is extensive formatting used.

Known issues:
The listed functions cause the program to exit:
	1.	Make Directory 
	2.	Undelete 
	3.	Remove Directory 
	4.	Write	
	5.	Remove
