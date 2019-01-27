//For testing functions in qolib
#include <stdlib.h>
#include <stdio.h>
#include "constants.h"
#include "qolib.h"
#include "qlist.h"
#include "qonum.h"

int main(void)
{
	// use qolnum
	qol_num a;
	qol_num b;

	a.i =	420;
	b.i = 69;

	qol_num * numbers = malloc(sizeof(qol_num)*10);
	for (int i=0;i<10;i++)
	{
		numbers[i].i = i*3;
	}	

	// use qol list
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

	// qol stacks
	for (int i=0;i<10;i++)
	{
		printf("storing %d\n",numbers[i].i);
		stack_push(stk,numbers[i]); 
	}

	for (int i=0;i<10;i++)
	{
		printf("popped %d\n",stack_pop(stk).i);
	}

	// qol log
	printf("Severity is %d\nRunning tests of log levels\n\n", SEVERITY);
	
	for (int i=0;i<5;i++)
	{
		qol_log(i," err");
		printf("%d\n\n",i);
	}

	// qol prime
	int notAPrime = 12;
	int aPrime = 7;

	printf("%d prime status: %d\r\n", notAPrime, isPrime(notAPrime));
	printf("%d prime status: %d\r\n", aPrime, isPrime(aPrime));

	return 420; // ecks dee
}
