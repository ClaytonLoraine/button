class SecretSong {

  public:
    int secretCombination;

    void CalculateCombination(int selectedPhrase, int code1, int code2, int code3, int code4, int code5, int phraseToPlay) {

      if (selectedPhrase == code1 && secretCombination == 0) {
        secretCombination = 1;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);
      }
      else if (selectedPhrase == code2 && secretCombination == 1) {
        secretCombination = 2;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);

      }
      else if (selectedPhrase == code3 && secretCombination == 2) {
        secretCombination = 3;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);

      }
      else if (selectedPhrase == code4 && secretCombination == 3) {
        secretCombination = 4;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);

      }
      else if (selectedPhrase == code5 && secretCombination == 4) {
        secretCombination = 5;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);
      }

      else if (selectedPhrase == 13) {
        //this is just here so someone can skip a song if they want
      }

      else if (selectedPhrase == 1 && secretCombination == 5) {
        phrase = phraseToPlay;
        secretCombination = 0;
      }
      else {
        secretCombination = 0;
      }
    }
};



//define secret song objects
SecretSong Song1;
SecretSong Song2;
SecretSong Song3;
SecretSong Song4;
SecretSong Song5;


//The collection of passphrases and thanks to those who supported us
void CheckSecrets() {
  //The OG 3
  //passphrase #1 - Cameron Privett
  Song1.CalculateCombination(phrase, 25, 16, 4, 15, 14, 71);
  //passphrase #2 - Clayton Loraine
  Song2.CalculateCombination(phrase, 16, 16, 4, 15, 14, 72);
  //passphrase #3 - Cameron Tanzyus
  Song3.CalculateCombination(phrase, 25, 10, 13, 16, 19, 73);

  //Those who helped us along the way
  //passphrase #4 - Peter Binder
  Song4.CalculateCombination(phrase, 25, 10, 13, 16, 19, 74);
  //passphrase #5 - Brett Barker
  Song5.CalculateCombination(phrase, 25, 10, 13, 16, 19, 75);
}
