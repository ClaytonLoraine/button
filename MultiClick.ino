
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
int shortPressMs = 200;


//track number of presses
int buttonPresses;

//time between click and doubleclicks
int timer;
int Click_delay = 190; //if you change this, chance shortPressMs too

//secret timer
int ssTimer = 0;

//button pin
int buttonPin = 2;

//Start/stop pins
int pin10 = 13;
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

  if (pressLength_milliSeconds >= longPressMs && clicks == 0) {
    ActivatePhrase(3);
  }

  //output option 2 after a medium press
  else if (pressLength_milliSeconds >= mediumPressMs && clicks == 0) {
    ActivatePhrase(2);
  }

  //ouput option 1 after a short press - set this one the same as the one further down
  else if (pressLength_milliSeconds >= shortPressMs && clicks == 0) {
    ActivatePhrase(1);
  }

  //output option 6 after a long press and a doubleclick
  else if (pressLength_milliSeconds >= longPressMs && clicks == 1) {
    ActivatePhrase(6);
  }

  //output option 5 after a medium press and a doubleclick
  else if (pressLength_milliSeconds >= mediumPressMs && clicks == 1) {
    ActivatePhrase(5);
  }

  //output option 4 after a short press and a double click
  else if (pressLength_milliSeconds >= shortPressMs && clicks == 1) {
    ActivatePhrase(4);
  }
  //output option 9 after a long press and a triple click
  else if (pressLength_milliSeconds >= longPressMs && clicks == 2) {
    ActivatePhrase(9);
  }

  //output option 8 after a medium press and a triple click
  else if (pressLength_milliSeconds >= mediumPressMs && clicks == 2) {
    ActivatePhrase(8);
  }

  //output option 7 after a short press and a triple click
  else if (pressLength_milliSeconds >= shortPressMs && clicks == 2) {
    ActivatePhrase(7);
  }

  //output secret song after 6000 milliseconds and 20 clicks
  else if (pressLength_milliSeconds >= 6000 && clicks == 19) {
    ActivatePhrase(102);
  }

  //Ouput a double click if button is clicked twice in quick succession
  else if (pressLength_milliSeconds > 0) {

    //while loop for double click timer
    while (timer <= Click_delay) {

      //if the button is clicked within timer, output doubleclick
      if (digitalRead(buttonPin) == LOW) {
        clicks++;
        Serial.print("Clicks = ");
        Serial.println(clicks);
        break;

      }

      //timer for double click
      else {
        if (timer <= Click_delay) {
          delay(20);
          timer += 20;
          Serial.print("timer = ");
          Serial.println(timer);
        }

        //if the timer runs out but no double click is found, use this one as a backup
        if (timer > Click_delay) {

          Serial.print("Click Times = ");
          Serial.println(clicks);

          if (clicks == 0) {
            ActivatePhrase(1);
          }
          if (clicks == 1) {
            ActivatePhrase(4);
          }
          if (clicks == 2) {
            ActivatePhrase(7);
          }

          //easteregg
          if (clicks == 14) {
            ActivatePhrase(101);
          }

          //reset clicks
          clicks = 0;
        }
      }
    }
  }

  //reset timer and presslength
  timer = 0;
  pressLength_milliSeconds = 0;
}
