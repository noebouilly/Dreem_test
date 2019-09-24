#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "clock.h"
#include "acquisition.h"

int main(void)
{
    /* Creation of a thread to simulate the 200 Hz clock */
    pthread_t thread_clock;

    /* Creation of a thread to simulate the EGG sensor acquisition */
    pthread_t thread_algo;

    if (pthread_create(&thread_clock, NULL, clock_callback, NULL))
    {
	    printf("ERROR: Fail to create clock thread\n");
        /* Normally we would have put here a return with the corresponding
         * pre defined error code */
    }

    /* Opening the file to store the EGG datas */
    acquisition_binary_file = fopen("egg_sensor_acquisition.bin", "w");
    if (acquisition_binary_file == NULL)
    {
        printf("Impossible to write egg_sensor_acquisition.bin");
        pthread_exit(NULL);
    }

    /* Infinite loop to check the clock value and lauch the acquisition
     * algorithm on every rising edge */
    while(1)
    {
        if (clock_200Hz == CLOCK_UP)
        {
            if (pthread_create(&thread_algo, NULL, algo, NULL))
            {
	            printf("ERROR: Fail to create acquisition algo thread\n");
                /* Normally we would have put here a return with the corresponding
                 * pre defined error code */
            }

            while (clock_200Hz == CLOCK_UP)
            {
                usleep(1);
            }
        }
    }

    fclose(acquisition_binary_file);
    return 0;
}