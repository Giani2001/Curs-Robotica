## Homework 4 - 4 digit 7 segment display and shift register

### Task Requirements:
Use the joystick to move through the 4 digit 7
segment displays digits, press the button to lock in on the current digit
and use the other axis to increment or decrement the number. Keep the
button pressed to reset all the digit values and the current position to the
first digit in the first state.

### States that we are using:
* First state: you can use a joystick axis to cycle through the 4 digits;
using the other axis does nothing. A blinking decimal point shows
the current digit position. When pressing the button, you lock in on
the selected digit and enter the second state.
* Second state: in this state, the decimal point stays always on, no
longer blinking and you can no longer use the axis to cycle through
the 4 digits. Instead, using the other axis, you can increment on
decrement the number on the current digit IN HEX (aka from 0
to F, as in the lab). Pressing the button again returns you to the
previous state. Also, keep in mind that when changing the number,
you must increment it for each joystick movement - it should not
work continuosly increment if you keep the joystick in one position
(aka with joyMoved).
* Reset: toggled by long pressing the button only in the first state.
When resetting, all the digits go back to 0 and the current position
is set to the first (rightmost) digit, in the first state.


### Components:
*  4 digit 7 segment display
*  4 rezistors 1k ohms
* 1 joystick
* wires
* shift register

### Pictures:
#### Component
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework4/homework4.jpeg?raw=true)




### Link to the code:
[Link to the 4th homework code!](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework4/homework4.ino)

### Link to the video:
[Link to the video!](https://youtube.com/shorts/_WkBwA_8eAo?feature=share)
