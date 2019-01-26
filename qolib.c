#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "constants.h"
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

void qassert(int test)
{
	if(!test)
		qol_cab("Failed assert");
}

void msg_assert(int test, char * msg)
{
	char out[40];
	if (!test)
	{
		strcpy(out,"Failed: ");
		strcat(out,msg);
		qol_cab(out);
	}
}

void qol_log(int severity,char * msg)
{
	if (SEVERITY>severity){
		return;	
	}

	time_t curr_t;
	char * t_string;
	curr_t = time(NULL);
	msg_assert(curr_t != ((time_t)-1),"Check time assignment");
	t_string = ctime(&curr_t);
	msg_assert(t_string!=NULL,"Check time string NULL");

	FILE * fp;

	fp = fopen("error.log","a");

	char * out = (char *)malloc(20);	
	
	switch(severity)
	{
		case 0:
		out="Debug:";
		break;
		case 1:
		out="Info:";
		break;
		case 2:
		out="Warning:";
		break;
		case 3:
		out="Error:";
		break;
		case 4:
		out="Critical:";
		break;
		default:
		qol_cab("Incorrect severity code!");
	}
	
	fprintf(stderr,"%s %s\n",out,msg);
	fprintf(fp,"%s %s %s\n",t_string,out,msg);
	fclose(fp);
}

qol_num * stopwatch( int (*f)() ,double test_num)
{
	qol_num * generic = malloc(sizeof(qol_num)*2);
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


