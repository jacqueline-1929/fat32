Project Summary:
This code provides a FAT32 file system with the following functions implemented and working properly: 

	1.	Close 	(cmd: close <FILE>)
	2.	Create 	(cmd: create <FILE>)
	3.	Open 	 (cmd: open <FILE> <r/w/rw>)
	4.	Read 	(cmd: read <FILE> <startnum> <num_bytes>)
	5.	Change Directory	(cmd: cd <DIR>)
	6.	List 		(cmd: ls)
	7.	Size 	(cmd: size <FILE>)
The source code is implemented in C++ and a makefile is included.


General Information:

Client.cpp has the majority of the logic. There are no other cpp files, only the utils.h files, which is included in the client.cpp file. Const is used often as a precautionary measure. Much of the logic is implemented using if statements, and there is extensive formatting used.

Known issues:
The listed functions cause the program to exit:
	1.	Make Directory 
	2.	Undelete 
	3.	Remove Directory 
