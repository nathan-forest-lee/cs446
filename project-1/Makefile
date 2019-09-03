# ------------------------------------------------------------------------------
#
# FILE NAME: Makefile
#
# DESCRIPTION: Makefile for a C++ program
#
# PURPOSE: Build a program executable
#
# MODIFICATION HISTORY:
#
# Author Date Modification(s)
# ----------- ---------- ---------------
# Nathan Lee	2019-09-01	version 1.0 for cs_446_project_1
#_______________________________________________________________________________


#	This is our original generic makefile command that will build
#	any stand alone ".cpp" source file.
#	Usage: e.g., make test

.cpp :
	g++ -o $* $*.cpp -std=c++11

sim1: Sim1_imp.cpp Sim1.h

#Set2: Node.cpp Node.h

#	This will build the two object files required for "singly_linked_list"
#	and link them into a single executable.
#	Usage:	make linked_list_demo

#singly_linked_list: singly_List.o singly_linked_list.oas
#	g++ -o $@ $@.o Int_List.o -std=c++11

#	This will build the two object files required for "singly_linked_list"
#	which are dependent on Int_List.h

#%.o : %.cpp singly_List.h
#	g++ -c $< -std=c++11

#randomPractice: RandomPracticeImp.cpp RandomPractice.h
#doublyLinkedList: DoublyListPractice.cpp DoublyListPractice.h
#test: Node.cpp Node.h
