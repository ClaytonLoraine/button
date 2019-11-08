void ActivatePhrase(int phraseNumber) {

  int binaryDelay = 20;

  //reset the pins (just in case)
  resetPins();

  //plays the phrase number that is set

  //RickRoll
  if (phraseNumber == 100 || buttonPresses >= 75) {
    phraseNumber = 100;
    //01100100
    digitalWrite(pin7, HIGH);
    digitalWrite(pin6, HIGH);
    digitalWrite(pin3, HIGH);
  }
  else if (phraseNumber == 101) {
    //01100101
    digitalWrite(pin7, HIGH);
    digitalWrite(pin6, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin1, HIGH);
  }
  else if (phraseNumber == 102) {
    //01100110
    digitalWrite(pin7, HIGH);
    digitalWrite(pin6, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
  }
  else if (phraseNumber == 1) {
    //00000001
    digitalWrite(pin1, HIGH);

    //SecretSong(3000, 8000);
  }
  else if (phraseNumber == 2) {
    //00000010
    digitalWrite(pin2, HIGH);
  }
  else if (phraseNumber == 3) {
    //00000011
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, HIGH);
  }
  else if (phraseNumber == 4) {
    //00000100
    digitalWrite(pin3, HIGH);
  }
  else if (phraseNumber == 5) {
    //00000101
    digitalWrite(pin3, HIGH);
    digitalWrite(pin1, HIGH);

  }
  else if (phraseNumber == 6) {
    //00000110
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
  }
  else if (phraseNumber == 7) {
    //00000111
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, HIGH);
  }
  else if (phraseNumber == 8) {
    //00001000
    digitalWrite(pin4, HIGH);
  }
  else if (phraseNumber == 9) {
    //00001001
    digitalWrite(pin4, HIGH);
    digitalWrite(pin1, HIGH);
  }

  //play
  digitalWrite(pin9, HIGH);
  delay(binaryDelay);

  //reset the pins back to LOW
  resetPins();

  clicks = 0;
  buttonPresses++;
  Serial.print("Phrase Activated = ");
  Serial.println(phraseNumber);
  Serial.print("Button Presses = ");
  Serial.println(buttonPresses);

  //digitalWrite(pin9, LOW);
}

void resetPins() {
  //set all pins to LOW
  digitalWrite(pin8, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin1, LOW);

  //playback pin to LOW
  digitalWrite(pin9, LOW);
}
