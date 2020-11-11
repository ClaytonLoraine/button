class SecretSong {

  public:
    int secretCombination;
    
    void CalculateCombination(int phraseNumber, int code1, int code2, int code3, int code4, int code5, int phraseToPlay) {

      if (phraseNumber == code1 && secretCombination == 0) {
        secretCombination = 1;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);
      }
      else if (phraseNumber == code2 && secretCombination == 1) {
        secretCombination = 2;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);

      }
      else if (secretCombination == 2) {
        secretCombination = 3;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);

      }
      else if (phraseNumber == code4 && secretCombination == 3) {
        secretCombination = 4;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);

      }
      else if (phraseNumber == code5 && secretCombination == 4) {
        secretCombination = 5;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);
      }

      else if (phraseNumber == 13) {
        //this is just here so someone can skip a song if they want
      }

      else if (secretCombination == 5)
        phrase = phraseToPlay;
      else {
        secretCombination = 0;
      }

      if (secretCombination > 1) {
        return 1;
      } else {
        return 0;
      }
    }
};
