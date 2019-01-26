/*
WARNING THIS CODE DOESN'T WORK
It is being kept in this state for historical purposes
I stopped it because void * is unsafe practice
from now on I will be using unions for generics
Last worked on ~6 PM 1/24/2019
*/
#define DEBUG
#ifndef _qolib_h
#define _qolib_h

typedef struct qol_piece qol_piece;

typedef struct qol_piece {
	void * data; //allows this to point to anything, may cause problems tho...
	qol_piece * ptr; //link is a cooler name
} qol_piece;

typedef struct qol_list {
	qol_piece * head;
	int length; //perhaps size would be better
}qol_list;

//Long names may be refractored, though also are useful
qol_list * qol_new_list(void * data);//Creates a new list
qol_list qol_list_from_array(void * arr);//TODO Creates lists from arrays
qol_piece qol_get_element(int index, qol_list l);//Gets the element at an index
void qol_add_element(qol_list * l, void * element);//Adds Element to end of list
void qol_add_piece(qol_list * list,qol_piece * piece);
qol_piece * qol_get_last(qol_list l);//Gets the last element in a list
qol_piece * qol_create_piece(void * element);//Allocates space and creates a new piece
void qol_cab(char * msg);


#ifdef DEBUG
//activate debug functions
void qol_print_list(qol_list l);
#endif

#endif
