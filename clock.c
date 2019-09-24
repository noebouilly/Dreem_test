#include <unistd.h>
#include <stdint.h>
#include "clock.h"

uint8_t clock_200Hz;

void* clock_callback(void* arg)
{
   while(1)
   {
       if (clock_200Hz == CLOCK_DOWN)
       {
            clock_200Hz = CLOCK_UP;
       }
       else
       {
            clock_200Hz = CLOCK_DOWN;
       }
   usleep(50);
   }
}