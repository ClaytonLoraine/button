/*

*/

void ActivatePhrase(int phraseNumber) {

  //reset the pins (just in case)
  ResetPins();

  //Stop whatever song is currently playing
  StopSong();

  //these phrases will not play if someone presses the combinaton to get them
  byte hiddenPhrases[] = {70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85};
  bool isHidden = false;
  bool isInvalid = false;

  //stop the song if the button is pressed 5 times no matter the length of the press
  if (phraseNumber > 255) {
    Serial.println("This phrase is invalid!");
    isInvalid = true;
  }
  else {
    
    if (isSongSecret == false) {
      //checks for hidden songs and doesn't play them if it is hidden, unless they are "secret songs"
      for (byte i = 0; i < (sizeof(hiddenPhrases)); i++) {
        if (phraseNumber == hiddenPhrases[i]) {
          isHidden = true;
          Serial.println("This phrase is hidden!");
          break;
        }
      }
    }

    if (phraseNumber == 13 || phraseNumber == 14 || phraseNumber == 15) {
      phraseNumber = HolidaySong();
    }

    //rickroll
    //generate random number

    //if a combination is in progress don't rickroll. This just gets annoying.
    int randomNumber = rand() % 150;
    // there is a 1/150% chance that it will play phrase 50 instead of the chosen phrase
    if (randomNumber == 0) {
      phraseNumber = 70;
    }


    //convert number to binary and write to pins
    if (isHidden == false && isInvalid == false) {
      for (byte i = 0; i < (sizeof(binaryPins)); i++) {
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

      isSongSecret = false;
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
  for (byte i = 0; i < (sizeof(binaryPins)); i++) {
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

byte HolidaySong() {
  //These are required to check the month and hour
  bool century = false;
  bool h12Flag;
  bool pmFlag;
  
  byte phraseToPlay;

  //Holloween
  if ((rtc.getMonth(century) == 10 && rtc.getDate() == 31) || (rtc.getMonth(century) == 11 && rtc.getDate() == 1 && rtc.getHour(h12Flag, pmFlag) <= 5)) {
    phraseToPlay = 80;
  }
  //Christmas
  else if ((rtc.getMonth(century) == 12 && (rtc.getDate() == 24) || rtc.getDate() == 25)) {
    phraseToPlay = 81;
  }
  else {
    phraseToPlay = 13;
  }

  //return the phrase to play
  return phraseToPlay;
}
