void ActivatePhrase(int phraseNumber) {

  int binaryDelay = 20;

    digitalWrite(pin9, HIGH);
delay(20);
  digitalWrite(pin9, LOW);
    

  //RickRoll
  if (phraseNumber == 100 || buttonPresses >= 75) {
    phraseNumber = 100;
    //01100100
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, HIGH);
    digitalWrite(pin6, HIGH);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);

    delay(binaryDelay);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin3, LOW);
  }
  else if (phraseNumber == 101) {
    //01100101
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, HIGH);
    digitalWrite(pin6, HIGH);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, HIGH);

    delay(binaryDelay);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin1, LOW);
  }
  else if (phraseNumber == 102) {
    //01100110
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, HIGH);
    digitalWrite(pin6, HIGH);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, LOW);

    delay(binaryDelay);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
  }
  else if (phraseNumber == 1) {
    //00000001
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, HIGH);

    delay(binaryDelay);
    digitalWrite(pin1, LOW);

    //SecretSong(3000, 8000);
  }
  else if (phraseNumber == 2) {
    //00000010
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, LOW);

    delay(binaryDelay);
    digitalWrite(pin2, LOW);
  }
  else if (phraseNumber == 3) {
    //00000011
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, HIGH);

    delay(binaryDelay);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
  }
  else if (phraseNumber == 4) {
    //00000100
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);

    delay(binaryDelay);
    digitalWrite(pin3, LOW);
  }
  else if (phraseNumber == 5) {
    //00000101
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, HIGH);

    delay(binaryDelay);
    digitalWrite(pin3, LOW);
    digitalWrite(pin1, LOW);

  }
  else if (phraseNumber == 6) {
    //00000110
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, LOW);

    delay(binaryDelay);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
  }
  else if (phraseNumber == 7) {
    //00000111
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin1, HIGH);

    delay(binaryDelay);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);
  }
    else if (phraseNumber == 8) {
    //00001000
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, HIGH);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, LOW);

    delay(binaryDelay);
    digitalWrite(pin4, LOW);
  }
    else if (phraseNumber == 9) {
    //00001001
    digitalWrite(pin8, LOW);
    digitalWrite(pin7, LOW);
    digitalWrite(pin6, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, HIGH);
    digitalWrite(pin3, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin1, HIGH);

    delay(binaryDelay);
    digitalWrite(pin4, LOW);
    digitalWrite(pin1, LOW);
  }

  //digitalWrite(pin9, HIGH);

  clicks = 0;
  buttonPresses++;
  Serial.print("Phrase Activated = ");
  Serial.println(phraseNumber);
  Serial.print("Button Presses = ");
  Serial.println(buttonPresses);

  //digitalWrite(pin9, LOW);
}
