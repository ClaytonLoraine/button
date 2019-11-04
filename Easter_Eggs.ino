void SecretSong(int timeMin, int timeMax) {

  delay(timeMin);

  while (ssTimer <= timeMax) {

    //if the button is clicked within timer, output secret song
    if (digitalRead(buttonPin) == LOW) {
      Serial.println("Secret Song!");
      ActivatePhrase(100);
      ssTimer = 0;
      break;

    }

    //timer for double click
    else {
      if (ssTimer <= timeMax) {
        delay(50);
        ssTimer += 50;
        Serial.print("ssTimer = ");
        Serial.println(ssTimer);
      }

      //if the timer runs out but no double click is found, use this one as a backup
      if (ssTimer > timeMax) {
        ssTimer = 0;
      }
    }
  }
}
