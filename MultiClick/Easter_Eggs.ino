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
