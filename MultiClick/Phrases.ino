void ActivatePhrase(byte phraseNumber) {

  byte binaryDelay = 100;

  //these phrases will not play if someone presses the combinaton to get them
  byte hiddenPhrases[] = {100};
  bool isHidden = false;

  Serial.print("Phrase ");
  Serial.println(phraseNumber);
  Serial.println(" has been chosen!");


  //reset the pins (just in case)
  resetPins();

  //hidden songs
  for (byte i = 0; i < (sizeof(hiddenPhrases) -1 ); i++) {
    if (phraseNumber == hiddenPhrases[i]) {
      isHidden = true;
      Serial.print("This phrase is hidden!");
      break;
    }
  }
  //generate random number
  int randomNumber = rand() % 100;

  // there is a 1/100% chance that it will play phrase 50 instead of the chosen phrase
  if (randomNumber == 0) {
    phraseNumber = 50;
  }

  //convert number to binary and write to pins
    for (byte i = 0; i < (sizeof(binaryPins) -1); i++) {
      byte bit = bitRead(phraseNumber, i);
      if (bit == 1){
        digitalWrite(binaryPins[i], HIGH);
      }
      Serial.print(bit);
      Serial.println(" - ");
      Serial.println(binaryPins[i]);
    }


    //play
    digitalWrite(startPin, HIGH);

    //wait until the device can recognise the signals
    delay(binaryDelay);

  //reset the pins back to HIGH
  resetPins();

  //reset clicks and phrases
  clicks = 0;
  phrase = 0;
  Serial.print("Phrase Activated = ");
  Serial.println(phraseNumber);

  //digitalWrite(startPin, HIGH);
}

void resetPins() {
  //set all pins to HIGH

  //binary pins
  for (byte i = 0; i < (sizeof(binaryPins) -1); i++) {
    digitalWrite(binaryPins[i], LOW);
  }

  //playback pin to HIGH
  digitalWrite(startPin, LOW);

  //stop pin to HIGH
  digitalWrite(stopPin, LOW);
}
