//This file is for the lists originally created for qolib.c
//When possible there should be sub files for bigger grouped libs
//so that people can load them individually
#define DEBUG
#ifndef _qlist_h
#define _qlist_h
#include "qolib.h"

typedef struct qol_piece qol_piece;

typedef struct qol_piece {
	qol_num data; //switched to num union
	qol_piece * ptr; //link is a cooler name
} qol_piece;

typedef struct qol_list {
	qol_piece * head;
	int length; //perhaps size would be better
}qol_list;

//Long names may be refractored, though also are useful
//the long names make it easy to remember what a function does
//until there is a refrence sheet the names stay long
qol_list * qol_new_list(qol_num data);//Creates a new list
qol_piece * qol_get_element(qol_list l, int index);//Gets the element at an index
void qol_add_element(qol_list * l, qol_num element);//Adds Element to end of list
//void qol_add_piece(qol_list * list,qol_piece * piece);
qol_piece * qol_get_last(qol_list l);//Gets the last element in a list
qol_piece * qol_create_piece(qol_num element);//Allocates space and creates a new piece
void qol_delete_piece(qol_list * list, int index);

qol_num stack_pop(qol_list * list);
void stack_push(qol_list * list, qol_num n);

#ifdef DEBUG
//activate debug functions
void qol_print_list(qol_list l);
#endif

#endif

