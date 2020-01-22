void ActivatePhrase(int phraseNumber) {

  int binaryDelay = 40;

  //reset the pins (just in case)
  resetPins();

  //RickRoll
  if (buttonPresses >= 150) {
    phraseNumber = 50;
    buttonPresses = 0;
  }

  //play the phrase number
  switch (phraseNumber) {
    case 1:
      //00000001
      digitalWrite(pin1, LOW);
      break;
    case 2:
      //00000010
      digitalWrite(pin2, LOW);
      break;
    case 3:
      //00000011
      digitalWrite(pin2, LOW);
      digitalWrite(pin1, LOW);
      break;
    case 4:
      //00000100
      digitalWrite(pin3, LOW);
      break;
    case 5:
      //00000101
      digitalWrite(pin3, LOW);
      digitalWrite(pin1, LOW);
      break;
    case 6:
      //00000110
      digitalWrite(pin3, LOW);
      digitalWrite(pin2, LOW);
      break;
    case 7:
      //00000111
      digitalWrite(pin3, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin1, LOW);
      break;
    case 8:
      //00001000
      digitalWrite(pin4, LOW);
      break;
    case 9:
      //00001001
      digitalWrite(pin4, LOW);
      digitalWrite(pin1, LOW);
      break;
    case 10:
      //00001010
      digitalWrite(pin4, LOW);
      digitalWrite(pin2, LOW);
      break;
    case 11:
      //00001011
      digitalWrite(pin4, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin1, LOW);
      break;
    case 12:
      //00001100
      digitalWrite(pin4, LOW);
      digitalWrite(pin3, LOW);
      break;
    case 50:
      //00110010
      digitalWrite(pin6, LOW);
      digitalWrite(pin5, LOW);
      digitalWrite(pin2, LOW);
      break;
    case 51:
      //00110011
      digitalWrite(pin6, LOW);
      digitalWrite(pin5, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin1, LOW);
      break;
    case 52:
      //00110100
      digitalWrite(pin6, LOW);
      digitalWrite(pin5, LOW);
      digitalWrite(pin3, LOW);
      break;
    case 53:
      //00110101
      digitalWrite(pin6, LOW);
      digitalWrite(pin5, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin3, LOW);
      break;
  }

  //play
  digitalWrite(pin9, LOW);
  delay(binaryDelay);

  //reset the pins back to HIGH
  resetPins();

  clicks = 0;
  buttonPresses++;
  Serial.print("Phrase Activated = ");
  Serial.println(phraseNumber);
  Serial.print("Button Presses = ");
  Serial.println(buttonPresses);

  //digitalWrite(pin9, HIGH);
}

void resetPins() {
  //set all pins to HIGH
  digitalWrite(pin8, HIGH);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin6, HIGH);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin1, HIGH);

  //playback pin to HIGH
  digitalWrite(pin9, HIGH);
}
