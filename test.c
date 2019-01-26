//For testing functions in qolib
#include <stdlib.h>
#include <stdio.h>
#include "qolib.h"
#include "qlist.h"

int main(void)
{
	qol_num a;
	qol_num b;

	a.i =	420;
	b.i = 69;

	qol_num * numbers = malloc(sizeof(qol_num)*10);
	for (int i=0;i<10;i++)
	{
		numbers[i].i = i*3;
	}	

	qol_list * l = qol_new_list(a);
	
	
	qol_print_list(*l);
	
	qol_add_element(l , b);
	
	qol_print_list(*l);

	for (int i=0;i<10;i++)
	{
		qol_add_element(l,numbers[i]);
	}
	qol_delete_piece(l,5);

	qol_delete_piece(l,7);
	qol_print_list(*l);
	
	qol_num temp;
	temp.i=4;
	qol_list * stk = qol_new_list(temp);

	for (int i=0;i<10;i++)
	{
		printf("storing %d\n",numbers[i].i);
		stack_push(stk,numbers[i]); 
	}

	for (int i=0;i<10;i++)
	{
		printf("popped %d\n",stack_pop(stk).i);
	}
	
	qol_log(3,"test 1");
	qol_log(4,"test 2");
	qol_log(0,"test 3");

	return 420;
}
