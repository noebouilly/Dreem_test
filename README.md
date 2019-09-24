***************
*  Dreem test *
*   25/09/19  *
* Noé BOUILLY *
***************


 How to lauch it
-----------------

- Simply "make" in the /dreem repertory
- launch ./dreem_test
- Results can be seen in egg_sensor_acquisition.bin


 Limitations / Areas of improvement
------------------------------------

- I chose to store the data consecutively in the bin file but I think it's probably not the best option.
Indeed, if everything is going well, we will be able to recover separately the 3 channels
because we know the size of every data, so we know that bytes nb 0, 12, 24, 36, ... are refering
to the first channel, bytes nb 4, 16, 28, 40, ... to the channel 2 and bytes nb 8, 20, 32, 44, ...
to the channel 3. However, if somehow we miss a sample, or don't completely write the 3 channels,
we risk to partially write an int32 and shift everything.

- Acquisition_binary_file and clock_200Hz are both global variables, thing that should be avoided.

- To avoid any problem, I could have used a mutex to lock every data wrote in the threads.


 Differences if I was working on a microcontroller
---------------------------------------------------

If I was on a real microcontroller, I wouldn't have to simulate a clock on a thread, I would have used
directly the sensor signal. Also, instead of making a condition in a while in main.c and a thread to
store the data, I would have used an interruption triggered by the sensor's clock rising edge and the
acquisition algorithm would have been in the interrupt handler.