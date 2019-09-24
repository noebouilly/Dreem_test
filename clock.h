#ifndef _CLOCK_H_DREEM_
#define _CLOCK_H_DREEM_

#include <stdint.h>

# define CLOCK_UP   1
# define CLOCK_DOWN 0

/* Function to simulate a 200 Hz clock and a global
 * variable to get the clock value in main function
 */

extern uint8_t clock_200Hz;

void* clock_callback(void* arg);

#endif // _CLOCK_H_DREEM