#ifndef _ACQUISITION_H_
#define _ACQUISITION_H_

#include <stdio.h>
#include <stdlib.h>

#define EGG_NUMBER_OF_CHANNELS 3

extern FILE* acquisition_binary_file;

/* This function is used to simulate the EGG sensor acquisiton */
void* algo(void* arg);

#endif // _ACQUISITION_H_