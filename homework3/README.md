# 7 segment display drawing

## Task Requirements:
You will use the joystick to control the position of
the segment and ”draw” on the display. The movement between segments
should be natural (meaning they should jump from the current position
only to neighbors, but without passing through ”walls”

## States that we are using:
* State 1 (default, but also initiated after a button press in State
2): Current position blinking. Can use the joystick to move from
one position to neighbors. Short pressing the button toggles state
2. Long pressing the button in state 1 resets the entire display by
turning all the segments OFF and moving the current position to the
decimal point.
* State 2 (initiated after a button press in State 1): The current
segment stops blinking, adopting the state of the segment before
selection (ON or OFF). Toggling the X (or Y, you chose) axis should
change the segment state from ON to OFF or from OFF to ON.
Clicking the joystick should save the segment state and exit back to
state 1.

## Components:
* 1 7-segment display
* 1 joystick
* resistors 
* wires

## Pictures:
### Component
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework3/components.jpeg?raw=true)


### Demo video:
https://youtu.be/V2ygBSWDOXQ


