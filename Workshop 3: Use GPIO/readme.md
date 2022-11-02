1. Write your own functions to control LED using GPIO HAL

2. Play sequence only while button is pressed

In your current implementation, you always iterate through all LEDs. Now change this logic. Iterate only when a button is pressed. If the button is pressed, released, and pressed again continue from the previous active LED.

Example for the sequence: RRGGGB

Button released => nothing
Button pressed for a 3 sec => RRG
Button released => nothing
Button pressed for a 2 sec => GG
Button released => nothing
Button pressed for a 5 sec => BRRGG


3. [Optional] Pause while LED is on

Think about how you can implement a mechanism so that if the button is released when the LED is on, it stays on.
