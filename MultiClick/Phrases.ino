void ActivatePhrase(int phraseNumber) {

  //reset the pins (just in case)
  ResetPins();

  //these phrases will not play if someone presses the combinaton to get them
  byte hiddenPhrases[] = {70, 71, 72, 73, 74, 75, 76, 77, 78, 79};
  bool isHidden = false;

  //stop the song if the button is pressed 5 times no matter the length of the press
  if (phraseNumber == 13 || phraseNumber == 14 || phraseNumber == 15) {
    StopSong();
  }
  else {


    //hidden songs
    for (byte i = 0; i < (sizeof(hiddenPhrases)); i++) {
      if (phraseNumber == hiddenPhrases[i]) {
        isHidden = true;
        Serial.println("This phrase is hidden!");
        break;
      }
    }

    //rickroll
    //generate random number

    //if a combination is in progress don't rickroll. This just gets annoying.
    int randomNumber = rand() % 100;
    // there is a 1/100% chance that it will play phrase 50 instead of the chosen phrase
    if (randomNumber == 0) {
      phraseNumber = 70;
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

      Serial.println();
      //play
      digitalWrite(startPin, LOW);
      delay(binaryDelay);

      Serial.print("Phrase Activated = ");
      Serial.println(phraseNumber);

    }
  }

  //reset the pins back to HIGH
  ResetPins();

  //reset clicks
  clicks = 0;

}
//used to reset the pins back to HIGH
void ResetPins() {
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
void StopSong() {

  Serial.println("Stopping Song...");

  digitalWrite(stopPin, LOW);
  delay(binaryDelay);
  ResetPins();

}
