/*Using a single button, create mutliple options based on how long the button is pressed and how mnay times it is pressed

  Note: This is being used with an AR-200R audio recorder set on binary playback mode
        The AR-200R

  by Clayton Loraine

  Uses snippets of code by J. Cameron Privett, Scuba Steve, and Michael James

*/

#include <DS3231.h>
#include <Wire.h>

/////////Declare and Initialize Variables////////////////////////////
//declare real time clock
DS3231 rtc;

//milliseconds that the button is pressed for
float pressLength_milliSeconds = 0;

//how long the button needs to be pressed to initiate a long press
const int longPressMs = 6000;
//how long the button needs to be pressed to initiate a medium press
const int mediumPressMs = 2000;
//how long the button needs to be pressed to initiate a short press
const int shortPressMs = 600; //Change this to change the double click delay

//time between click and doubleclicks
int timer;
int click_Delay;

//button pin
const byte buttonPin = 2;

//stop pin
const byte stopPin = 12;
//start pin
const byte startPin = 11;

//binary pins
const byte binaryPins[] = {3, 4, 5, 6, 7, 8, 9, 10};

//for tracking clicks 
int clicks = 0;

//the phrase to play
int phrase;

//set the delay for the device in ms
const int binaryDelay = 100;

void setup() {
  //begin Wire for the RTC
  Wire.begin();

  //Set the RTC date and time (uncomment and change if it needs to be changed)
  /*
  rtc.setYear(2021);
  rtc.setMonth(1);
  rtc.setDate(16);
  rtc.setHour(5);
  rtc.setMinute(16);
  rtc.setSecond(0);
  */
  
  //set click_Delay
  click_Delay = shortPressMs - 10;


  // Keep in mind, when pin 2 has ground voltage applied, we know the button is being pressed
  pinMode(buttonPin, INPUT_PULLUP);

  //set the stop and start pins as outputs
  pinMode(stopPin, OUTPUT);
  pinMode(startPin, OUTPUT);

  //set the binary pins as outputs
  for (byte i = 0; i < (sizeof(binaryPins)); i++) {
    pinMode(binaryPins[i], OUTPUT);
  }


  //Start serial communication - for debugging purposes only
  Serial.begin(9600);

  //reset the pins
  ResetPins();

}

void loop() {
  while (digitalRead(buttonPin) == LOW ) {

    delay(50);  //if you want more resolution, lower this number
    pressLength_milliSeconds = pressLength_milliSeconds + 50;


    //display how long button is has been held and the button presses
    Serial.print("ms = ");
    Serial.println(pressLength_milliSeconds);

  }//close while


  //calculate what phrase should be played
  //to do this we're going to add one to the click number
  //remember that the first click starts at 0
  //then multiply it by three
  //and add nothing, 1, or 2 depending on how long they hold it

  //example: if they press it three times then hold it for a long press
  //clicks will be 2 so it will add one (3) then multiply three
  //by three (9) then add two (11) so it will play phrase 11

  if (pressLength_milliSeconds >= longPressMs) {
    ActivatePhrase(CalculatePhrase(clicks, 3));
  }
  else if (pressLength_milliSeconds >= mediumPressMs) {
    ActivatePhrase(CalculatePhrase(clicks, 2));
  }
  else if (pressLength_milliSeconds >= shortPressMs) {
    ActivatePhrase(CalculatePhrase(clicks, 1));
  }

  //Ouput a double click if button is clicked twice in quick succession
  if (pressLength_milliSeconds > 0) {

    //while loop for double click timer
    while (timer <= click_Delay) {

      //if the button is clicked within timer, output doubleclick
      if (digitalRead(buttonPin) == LOW) {
        clicks++;
        Serial.print("Clicks = ");
        Serial.println(clicks);
        break;

      }

      //timer for double click
      else {
        if (timer <= click_Delay) {
          delay(20);
          timer += 20;
          Serial.print("timer = ");
          Serial.println(timer);
        }

        //if the timer runs out but no double click is found, use this one as a backup
        if (timer > click_Delay && pressLength_milliSeconds < click_Delay) {

          Serial.print("Click Times = ");
          Serial.println(clicks + 1);

          //play phrase
          ActivatePhrase(CalculatePhrase(clicks, 1));

          //reset clicks
          clicks = 0;
        }
      }
    }

    //reset timer and presslength
    timer = 0;
    pressLength_milliSeconds = 0;
  }
}

int CalculatePhrase(byte clickNumber, byte lengthAdditions) {
phrase = (clickNumber * 3) + lengthAdditions;
CheckSecrets(phrase);
return phrase;
}
