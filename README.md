# IntroductionInRobotics
HI everyone, this is my repo to upload my homeworks for the IntroductionInRobotics course!
## Homework1 - RGB Led

### Task Requirements:
 Use 3 different potentiometers to control the color of the RGB led( Red, Green, Blue). The control must be done with digital electronics(aka you must read the value of the potentiome-ter with Arduino, and write a mapped value to each of the pins connectedto the led.
 
### Components:
*	One RGB Led
*	Three potentiometers
*	Resistors
*	Wires
*	Arduino Uno Board
*	Breadboard

### Pictures:
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework1/setup_1.png?raw=true)

![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework1/setup_2.png?raw=true)


![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework1/red_light.png?raw=true)



![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework1/green_light.png?raw=true)


![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework1/blue_light.png?raw=true)

![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework1/simultaneous_lights.png?raw=true)

### Demo Video:
[Link to the first homework video!](https://youtu.be/tnK8BxJ770g)
### Link to the code:
[Link to the first homework code!](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework1/homework1_robotics.ino)


## Homework2 - CrossWalk

### Task Requirements:
Building the traffic lights for a crosswalk. You
will use 2 LEDs to represent the traffic lights for people (red and green)
and 3 LEDs to represent the traffic lights for cars (red, yellow and green).
See the states it needs to go through. If anything is not clear, ask. Also,
see the uploaded video (the intervals are different, but the states flow is
the same). It’s a traffic lights system for people and cars - don’t overthink
it.

### States that we are using:
* State 1 (default, reinstated after state 4 ends): green light for cars,
red light for people, no sounds. Duration: indefinite, changed by
pressing the button.
* State 2 (initiated by counting down 8 seconds after a button press):
the light should be yellow for cars, red for people and no sounds.
Duration: 3 seconds.
* State 3 (initiated after state 2 ends): red for cars, green for people
and a beeping sound from the buzzer at a constant interval. Duration:
8 seconds.
* State 4 (initiated after state 3 ends): red for cars, blinking green
for people and a beeping sound from the buzzer, at a constant in-
terval, faster than the beeping in state 3. This state should last 4
seconds

### Components:
* 5 leds: - 2 green
          - 1 yellow
          - 2 red
* 5 rezistors 220 ohm
* 1 resistor 100 for the buzzer
* wires
* one button and when pressing him the semaphor for pedestrians start to turn green 
* one buzzer for pedestrians crosswalk

### Pictures:
#### States3
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework2/State1.png?raw=true)

#### States2
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework2/State2.png?raw=true)
#### States3
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework2/State3.png?raw=true)

#### Demo video:
[Link to the second homework video!](https://youtube.com/shorts/et6-uQovdRg)



### Link to the code:
[Link to the second homework code!](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework2/homework2.ino)

## Homework3 - 7 segment display drawing

### Task Requirements:
You will use the joystick to control the position of
the segment and ”draw” on the display. The movement between segments
should be natural (meaning they should jump from the current position
only to neighbors, but without passing through ”walls”

### States that we are using:
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

### Components:
* 1 7-segment display
* 1 joystick
* resistors 
* wires

### Pictures:
#### Component
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework3/components.jpeg?raw=true)


#### Demo video:
[Link to the third homework video!](https://youtu.be/V2ygBSWDOXQ)


### Link to the code:
[Link to the third homework code!](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework3/homework3.ino)

