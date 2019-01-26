/*
WARNING THIS CODE DOESN'T WORK
It is being kept in this state for historical purposes
I stopped it because void * is unsafe practice
from now on I will be using unions for generics
Last worked on ~6 PM 1/24/2019
*/
#define DEBUG
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "qolib.h"

//Got tired of writing things out so now
//I will use preprocessor for my laziness
#define qpiece qol_piece
#define qlist qol_list
#define qat(n) qol_get_element(n)
#define qlast(l) qol_get_last(l)
#define qad(l,e) qol_add_element(l,e)

void qol_connect_pieces(qpiece * first, qpiece * last);

//cab stands for CRASH AND BURN
//Should this be a public function?
void qol_cab (char * msg) 
{
	fprintf(stderr,msg);
	if (access("crash.log",F_OK)!=-1)
	{
		FILE *fp;
		fp = fopen("crash.log", "a");
		fputs(msg,fp);
		fclose(fp);
	}
	exit(EXIT_FAILURE);
} 

qol_list * qol_new_list(void * data)
{
	qpiece * head = malloc(sizeof(qpiece));
	qol_list * list = malloc(sizeof(qlist));
	head->data = data;
	head->ptr = NULL;
	list->length = 1;
	list->head = head;
	return list;
}
/*
qol_list qol_list_from_array(void * arr)
{
	qol_list list;
	int length = sizeof(arr)/sizeof(arr[0]);
	
	list.length = length;

	qol_piece old_p;

	for (int i = 0;i<length;i++)
	{
		qol_piece p = {arr[i],
	}
}
*/
qol_piece qol_get_element(int index, qol_list l)
{
	if (index>l.length)	
	{
		qol_cab("Index out of bounds: get element");
	}
	qol_piece * ptr = l.head;
	for (int i = 0;i<index-1;i++){
		ptr = ptr->ptr;
	}
	return *ptr;
}

qol_piece * qol_get_last(qol_list l)
{
	if(l.length==1){
		return l.head;
	}
	qol_piece * ptr = l.head;
	while (ptr != NULL) {
		ptr = ptr->ptr;
	}
	return ptr;
}

void qol_add_element(qol_list * l, void * element)
{
	qol_piece * piece = qol_get_last(*l);
	qol_piece * new_piece = malloc(sizeof(qol_piece));
	new_piece->data = element;
	new_piece->ptr = NULL;
	qol_connect_pieces(piece,new_piece);
	l->length = l->length+1; 
}	

void qol_add_piece(qol_list * list, qol_piece * piece)
{
	qol_piece * tail = qol_get_last(*list);
	qol_connect_pieces(tail,piece);
	list->length = list->length+1;
}

qol_piece * qol_create_piece(void * element)
{
	qol_piece * piece = malloc(sizeof(qol_piece));
	piece->data=element;
	piece->ptr=NULL;
	return piece;
}

//Not to be used outside this file, breaks lists!
void qol_connect_pieces(qol_piece * first, qol_piece * last)
{
		first->ptr = last;
}

#ifdef DEBUG
//For testing purposes only
void qol_print_list(qol_list l) 
{
	for(int i=0;i<l.length;i++)
	{
	//Very inneficient, would make sense to hop from
	//ptr to ptr but I'm lazy
		int * o = qol_get_element(i,l).data;
		printf("%d ",*o);
	}
	printf("\n");
}

#endif
