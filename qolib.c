#define DEBUG
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "qolib.h"

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

qol_num * stopwatch( int (*f)() ,double test_num)
{
	qol_num generic[2];
	struct timespec before_time,after_time;
	timespec_get(&before_time, TIME_UTC);
	generic[0].i = (*f)(test_num); //test if succeeds
	timespec_get(&after_time, TIME_UTC);
	double elapsed = (double)(after_time.tv_nsec - before_time.tv_nsec);
  generic[1].d = (((double)elapsed)/1000000000);	
	//DEBUG LINE// printf("%llf time , %d succ",amazon[1].num.l,amazon[0].num.i);
	return generic;
}

void print_array(int * i)
{
	int length = (sizeof(i)/sizeof(i[0]));
	for (int j=0;j<length;j++)
	{
		printf("%d ",i[j]);
	}
	printf("\n");
}


