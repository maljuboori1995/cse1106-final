1. I made it so that we can run the code from the terminal as if it was a raspberry pi itself. #ifdef RASPBERRY_PI and everything.
   I made it so that it doesn't just return 1 when there's an error. I made it go to a cleanup section that turns off the LED if it's on.
   I made the function void set_led(state); If we're on a Raspberry Pi it turns on the actual LED, and it also prints LED: ON/OFF on screen.
   
2. I wasn't familiar with c, so I needed to learn a lot of syntax. We don't have a micro HDMI cable for our PI, so within our code,
   I made it so that the LED physically turns ON/OFF without the Raspberry Pi screen turned on, we entered temperatures through the terminal.
3. We tested different commands on the terminal. Getting the LED to turn on without access to the Raspberry PI screen was a struggle.
   I needed to download Git and download libraries within the terminal for #ifdef RASPBERRY_PI to work, etc.
4. Nothing? I needed to figure everything out from scratch almost. What I was doing required a lot of thinking especially, CSE 1106 labs are
   just "follow the steps" class.
5. Adding a temperature sensor.
