/*Using a Single Button, create mutliple options based on how long the button is pressed and how mnay times it is pressed

   Note 1: on most Arduinos there is already an LED on the board
  attached to pin 13.
   Note 2: In this circuit, when the button is pressed, Ground Voltage is what will be applied.

  by Clayton Loraine

  Uses snippets of code by Scuba Steve, Michael James, and J. Cameron Privett

*/


/////////Declare and Initialize Variables////////////////////////////
//milliseconds that the button is pressed for
float pressLength_milliSeconds = 0;
int longPressMs = 8000;
int mediumPressMs = 2000;
int shortPressMs = 400; //Change this to change the double click delay

//time between click and doubleclicks
int timer;
int click_Delay;

//secret timer
int ssTimer = 0;

//button pin
int buttonPin = 2;

//stop pin
int pin10 = 13;
//start pin
int pin9 = 12;


//binary pins
int pin8 = 11;
int pin7 = 10;
int pin6 = 9;
int pin5 = 8;
int pin4 = 7;
int pin3 = 6;
int pin2 = 5;
int pin1 = 4;

//for tracking doubleclicks
int clicks = 0;

void setup() {
  //set click_Delay
  click_Delay = shortPressMs - 10;


  // Keep in mind, when pin 2 has ground voltage applied, we know the button is being pressed
  pinMode(buttonPin, INPUT_PULLUP);

  //set the LEDs pins as outputs
  pinMode(pin10, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin1, OUTPUT);


  //Start serial communication - for debugging purposes only
  Serial.begin(9600);

  //reset the pins
  resetPins();

}

void loop() {
  while (digitalRead(buttonPin) == LOW ) {

    digitalWrite(pin10, HIGH);

    delay(50);  //if you want more resolution, lower this number
    pressLength_milliSeconds = pressLength_milliSeconds + 50;

    digitalWrite(pin10, LOW);


    //display how long button is has been held and the button presses
    Serial.print("ms = ");
    Serial.println(pressLength_milliSeconds);

  }//close while


  switch (clicks) {
    case 0:
      if (pressLength_milliSeconds >= longPressMs) {
        ActivatePhrase(3);
      }

      //output option 2 after a medium press
      else if (pressLength_milliSeconds >= mediumPressMs) {
        ActivatePhrase(2);
      }

      //ouput option 1 after a short press - set this one the same as the one further down
      else if (pressLength_milliSeconds >= shortPressMs) {
        ActivatePhrase(1);
      }
      break;

    case 1:
      //output option 6 after a long press and a doubleclick
      if (pressLength_milliSeconds >= longPressMs) {
        ActivatePhrase(6);
      }

      //output option 5 after a medium press and a doubleclick
      else if (pressLength_milliSeconds >= mediumPressMs) {
        ActivatePhrase(5);
      }

      //output option 4 after a short press and a double click
      else if (pressLength_milliSeconds >= shortPressMs) {
        ActivatePhrase(4);
      }
      break;

    case 2:
      //output option 9 after a long press and a triple click
      if (pressLength_milliSeconds >= longPressMs) {
        ActivatePhrase(9);
      }

      //output option 8 after a medium press and a triple click
      else if (pressLength_milliSeconds >= mediumPressMs) {
        ActivatePhrase(8);
      }

      //output option 7 after a short press and a triple click
      else if (pressLength_milliSeconds >= shortPressMs) {
        ActivatePhrase(7);
      }
      break;
    case 3:
      //output option 12 after a long press and a quadruple click
      if (pressLength_milliSeconds >= longPressMs) {
        ActivatePhrase(12);
      }

      //output option 11 after a medium press and a quadruple click
      else if (pressLength_milliSeconds >= mediumPressMs) {
        ActivatePhrase(11);
      }

      //output option 10 after a short press and a quadruple click
      else if (pressLength_milliSeconds >= shortPressMs) {
        ActivatePhrase(10);
      }
      break;

    case 14:
      //output secret song after a meduim press milliseconds and 15 clicks
      if (pressLength_milliSeconds >= mediumPressMs) {
        ActivatePhrase(53);
      }
      break;
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
          Serial.println(clicks);


          switch (clicks) {
            case 0:
              ActivatePhrase(1);
              break;

            case 1:
              ActivatePhrase(4);
              break;

            case 2:
              ActivatePhrase(7);
              break;

            case 3:
              ActivatePhrase(10);
              break;

            //seasonal
            case 4:
              ActivatePhrase(52);
              break;

            //easteregg
            case 9:
              ActivatePhrase(51);
              break;
          }

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
