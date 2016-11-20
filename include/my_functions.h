#ifndef _MY_FUNCTIONS_
#define _MY_FUNCTIONS_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int max3(int a, int b, int c);


//++ get length ofthe biggest commum prefix of stringA and stringB
int getPrefix(char* stringA ,char* stringB);                //ok


//++ get string of the biggest commum prefix of stringA and stringB
char* getPrefixString(char* stringA ,char* stringB);        //ok

void devAlgavAllTest();
#endif
