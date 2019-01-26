#include <stdlib.h>
#include <stdio.h>
#include "qolib.h"
#include "qlist.h"

qol_list * qol_new_list(qol_num data)
{
	qol_piece * head = qol_create_piece(data);
	qol_list * list = malloc(sizeof(qol_list));
	list->length = 1;
	list->head = head;
	return list;
}

qol_piece * qol_get_element(qol_list l , int index)//TECHNICALLY SHOULD BE get_piece
{
	if (index>l.length)	
	{
		qol_cab("Index out of bounds: get element");
	}
	qol_piece * ptr = l.head;
	for (int i = 0;i<index-1;i++){
		ptr = ptr->ptr;
	}
	return ptr;
}

qol_piece * qol_get_last(qol_list l)
{
	qol_piece * currPos = l.head;
	int d=1;
	while (currPos->ptr != NULL) {
		d++;
		currPos = currPos->ptr;
	}
	return currPos;
}

void qol_add_element(qol_list * l, qol_num element)
{
	qol_piece * piece = qol_get_last(*l);
	qol_piece * new_piece = qol_create_piece(element);
	piece->ptr = new_piece;
	l->length = l->length+1; 
}	

/* Shouldn't be an option, too low level
void qol_add_piece(qol_list * list, qol_piece * piece)
{
	qol_piece tail = *(qol_get_last(*list));
	tail.ptr = piece;
	piece->ptr = NULL;
	list->length = list->length+1;
}
*/

qol_piece * qol_create_piece(qol_num element)
{
	qol_piece * piece = malloc(sizeof(qol_piece));
	piece->data=element;
	piece->ptr=NULL;
	return piece;
}

void qol_delete_piece(qol_list * list, int index)
{
	if (list->length<=index)
	{
		qol_cab("Index Out of Bounds in delete piece");
	}
	if (index == 0)
	{
		list->length = list->length-1;
		list->head = list->head->ptr;
	}
	qol_piece * p_before = qol_get_element(*list , index-1);
	p_before->ptr = p_before->ptr->ptr;
	list->length = list->length-1;
}


qol_num stack_pop(qol_list * stk)
{
	if (stk->length == 0)
	{
		qol_cab("list is size 0");
	}	
	qol_num o = stk->head->data;
	stk->head = stk->head->ptr;
	return o;
}

void stack_push(qol_list * stk, qol_num n)
{
	qol_piece * p = qol_create_piece(n);
	p->ptr = stk->head;
	stk->head = p;
}

//For testing purposes only
void qol_print_list(qol_list l) 
{
	qol_piece * curr_piece = l.head;
	do {
		printf("%d ",curr_piece->data.i);
		curr_piece = curr_piece->ptr;
	} while(curr_piece!=NULL);
	printf("\n");
}

