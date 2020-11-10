void ActivatePhrase(int phraseNumber) {

  //reset the pins (just in case)
  resetPins();

  //these phrases will not play if someone presses the combinaton to get them
  byte hiddenPhrases[] = {63};
  bool isHidden = false;

  if (phraseNumber == 21) {
    stopSong();
  }
  else {


    //hidden songs
    for (byte i = 0; i < (sizeof(hiddenPhrases)); i++) {
      if (phraseNumber == hiddenPhrases[i]) {
        isHidden = true;
        Serial.print("This phrase is hidden!");
        break;
      }
    }

    //rickroll
    //generate random number
    int randomNumber = rand() % 100;
    // there is a 1/100% chance that it will play phrase 50 instead of the chosen phrase
    if (randomNumber == 0) {
      phraseNumber = 63;
    }


    //convert number to binary and write to pins
    if (isHidden == false) {
      for (byte i = 0; i < (sizeof(binaryPins) - 1); i++) {
        byte bit = bitRead(phraseNumber, i);
        if (bit == 1) {
          digitalWrite(binaryPins[i], LOW);
        }
        Serial.print(bit);
      }

      //play
      digitalWrite(startPin, LOW);
      delay(binaryDelay);

      Serial.println("Phrase Activated = ");
      Serial.print(phraseNumber);

    }
  }

  //reset the pins back to HIGH
  resetPins();

  //reset clicks
  clicks = 0;

}
//used to reset the pins back to HIGH
void resetPins() {
  //set all pins to HIGH

  //binary pins
  for (byte i = 0; i < (sizeof(binaryPins) - 1); i++) {
    digitalWrite(binaryPins[i], HIGH);
  }

  //playback pin to HIGH
  digitalWrite(startPin, HIGH);

  //stop pin to HIGH
  digitalWrite(stopPin, HIGH);
}

//used to stop the current song from playing
void stopSong() {

  Serial.print("Stopping Song...");

  digitalWrite(stopPin, LOW);
  delay(binaryDelay);
  resetPins();

}
