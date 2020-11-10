//possible to use for different timed clicks to add easter eggs in BETA
void SecretSong(int timeStart, int timeLength, int currentPhrase) {

  int ssDelayTimer = 0;
  int ssTimer = 0;


  while (ssDelayTimer <= timeStart) {

    //if the button is clicked while the delay is happening, cancel the secret song
    if (digitalRead(buttonPin) == LOW) {
      exit;;
    }
    //timer for delay
    else {
      if (ssTimer <= timeLength) {
        delay(50);
        ssDelayTimer += 50;
        Serial.print("delayTimer = ");
        Serial.println(ssDelayTimer);
      }
    }
  }

  while (ssTimer <= timeLength) {

    //if the button is clicked within timer, output secret song
    if (digitalRead(buttonPin) == LOW) {
      Serial.println("Secret Song!");
      ActivatePhrase(100);
      break;

    }

    //timer for double click
    else {
      if (ssTimer <= timeLength) {
        delay(50);
        ssTimer += 50;
        Serial.print("ssTimer = ");
        Serial.println(ssTimer);
      }

      //if the timer runs out but no double click is found, use this one as a backup
      if (ssTimer >= timeLength) {
        break;
      }
    }
  }
}

void CalculateCombination(int phraseNumber) {

  if (phraseNumber == 9 && secretCombination == 0) {
    secretCombination = 1;
    Serial.print("1");
  }
  else if (phraseNumber == 4 && secretCombination == 1) {
    secretCombination = 2;
    Serial.print("2");
  }
  else if (phraseNumber == 34 && secretCombination == 2) {
    secretCombination = 3;
    Serial.print("3");
  }
  else if (phraseNumber == 7 && secretCombination == 3) {
    secretCombination = 4;
    Serial.print("4");
  }
  else if (phraseNumber == 13 || phraseNumber == 14) {
    if (secretCombination == 4) {
      secretCombination = 5;
      Serial.print("5");
    }
    else
    {

    }
  }
  else {
    secretCombination = 0;
  }
}
