#ifndef _qolib_h
#define _qolib_h

#include "constants.h"

void qol_cab(char * msg);
void qol_log(int severity,char * msg);
void qassert(int test);

qol_num * stopwatch( int (*f)() ,double test_num);

void print_array(int * i);

#endif
