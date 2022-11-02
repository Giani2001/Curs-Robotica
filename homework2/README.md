# CrossWalk

## Task Requirements:
Building the traffic lights for a crosswalk. You
will use 2 LEDs to represent the traffic lights for people (red and green)
and 3 LEDs to represent the traffic lights for cars (red, yellow and green).
See the states it needs to go through. If anything is not clear, ask. Also,
see the uploaded video (the intervals are different, but the states flow is
the same). It’s a traffic lights system for people and cars - don’t overthink
it.

## States that we are using:
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

## Components:
* 5 leds: - 2 green
          - 1 yellow
          - 2 red
* 5 rezistors 220 ohm
* 1 resistor 100 for the buzzer
* wires
* one button and when pressing him the semaphor for pedestrians start to turn green 
* one buzzer for pedestrians crosswalk

## Pictures:
### States3
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework2/State1.png?raw=true)

### States2
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework2/State2.png?raw=true)
### States3
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework2/State3.png?raw=true)

### Demo video:
https://youtube.com/shorts/et6-uQovdRg

