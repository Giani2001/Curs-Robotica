# Matrix Menu

## Task Requirements:
Menu Task: Create a menu for your game, emphasis on the game. Youshould scroll on the LCD with the joystick. Remember you have quite alot of flexibility here, but do not confuse that with a free ticket to slackoff. The menu should include the following functionality:
* When powering up a game, a greeting message should be shown for
a few moments.
* Should contain roughly the following categories :
  * Start game, starts the initial level of your game
  * Highscore:
     * Initially, we have 0.
     * Update it when the game is done. Highest possible score
should be achieved by starting at a higher level.
     * Save the top 5+ values in EEPROM with name and score
  * Settings:
     *  Enter name. The name should be shown in highscore. Maybe
somewhere else, as well?
     * Starting level: Set the starting level value. The idea is to
be able to start from a higher level as well. Can be replaced
with difficulty.
     * LCD contrast control (optional, it replaces the potentiome-
ter). Save it to eeprom.
     * LCD brightness control (mandatory, must change LED wire
that’s directly connected to 5v). Save it to eeprom.
     * Matrix brightness control (see function setIntesnity from the
ledControl library). Save it to eeprom.
     * Sounds on or off. Save it to eeprom.

  * About: 
     * should include details about the creator(s) of the game.
     * At least game name, author and github link or user (use scrolling
text?)
   * How to play: 
     * short and informative description
 
## Components:
*	MAX7219
*	LCD Display
*	Wires
*	Arduino Uno Board
*	Matrix 8x8

## Pictures:
![alt text](https://github.com/Giani2001/IntroductionInRobotics/blob/main/homework5/homework5.jpeg?raw=true)


## Demo Video:
[https://youtu.be/b8PkiKXl1Rk)


