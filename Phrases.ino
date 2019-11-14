void ActivatePhrase(int phraseNumber) {

  int binaryDelay = 20;

  //reset the pins (just in case)
  resetPins();

  //plays the phrase number that is set

  //RickRoll
  if (phraseNumber == 50 || buttonPresses >= 100) {
    phraseNumber = 50;
    //00110010
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin2, LOW);

    buttonPresses = 0;

  }
  else if (phraseNumber == 51) {
    //00110011
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
  }
  else if (phraseNumber == 52) {
    //00110100
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin3, LOW);
  }
  else if (phraseNumber == 1) {
    //00000001
    digitalWrite(pin1, LOW);

    //SecretSong(3000, 8000);
  }
  else if (phraseNumber == 2) {
    //00000010
    digitalWrite(pin2, LOW);
  }
  else if (phraseNumber == 3) {
    //00000011
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
  }
  else if (phraseNumber == 4) {
    //00000100
    digitalWrite(pin3, LOW);
  }
  else if (phraseNumber == 5) {
    //00000101
    digitalWrite(pin3, LOW);
    digitalWrite(pin1, LOW);

  }
  else if (phraseNumber == 6) {
    //00000110
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
  }
  else if (phraseNumber == 7) {
    //00000111
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
  }
  else if (phraseNumber == 8) {
    //00001000
    digitalWrite(pin4, LOW);
  }
  else if (phraseNumber == 9) {
    //00001001
    digitalWrite(pin4, LOW);
    digitalWrite(pin1, LOW);
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
