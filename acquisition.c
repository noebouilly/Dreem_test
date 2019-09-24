#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include "acquisition.h"

FILE* acquisition_binary_file;

void* algo(void* arg)
{
    /* We create 3 variables to simulates the 3 EGG sensor channels */
    int32_t data[EGG_NUMBER_OF_CHANNELS] = {0x11111111, 0x22222222, 0x33333333};

    /* We write consecutively 3 blocks of int32 size in the binary file */
    fwrite(data, sizeof(int32_t), EGG_NUMBER_OF_CHANNELS, acquisition_binary_file);

    pthread_exit(NULL);
}