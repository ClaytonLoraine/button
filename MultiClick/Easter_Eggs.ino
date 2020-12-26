
bool isSongSecret = false;

class SecretSong {

  public:
    int secretCombination;

    void CalculateCombination(int selectedPhrase, int code1, int code2, int code3, int code4, int code5, int phraseToPlay) {

      if (selectedPhrase == code1 && secretCombination == 0) {
        secretCombination = 1;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);
        if (code2 == 0) {
          StopSong();
          phrase = phraseToPlay;
          secretCombination = 0;
          isSongSecret = true;
        }
      }
      else if (selectedPhrase == code2 && secretCombination == 1) {
        secretCombination = 2;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);
        if (code3 == 0) {
          StopSong();
          phrase = phraseToPlay;
          secretCombination = 0;
          isSongSecret = true;
        }

      }
      else if (selectedPhrase == code3 && secretCombination == 2) {
        secretCombination = 3;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);
        if (code4 == 0) {
          StopSong();
          phrase = phraseToPlay;
          secretCombination = 0;
          isSongSecret = true;
        }
      }
      else if (selectedPhrase == code4 && secretCombination == 3) {
        secretCombination = 4;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);
        if (code5 == 0) {
          StopSong();
          phrase = phraseToPlay;
          secretCombination = 0;
          isSongSecret = true;
        }
      }
      else if (selectedPhrase == code5 && secretCombination == 4) {
        secretCombination = 5;
        Serial.print(secretCombination);
        Serial.print(" - Secret Song #");
        Serial.println(phraseToPlay);
        StopSong();
        phrase = phraseToPlay;
        secretCombination = 0;
        isSongSecret = true;
      }
      else if (selectedPhrase != 13) {
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
//How the objects are laid out:
//(phrase to be checked (pretty much always going to be "phrase"), first digit of code, second digit, third, fourth, fifth, phrase to play when code is successful)
void CheckSecrets(int phraseToBeChecked) {
  //The OG 3
  //passphrase #1 - Cameron Privett
  Song1.CalculateCombination(phraseToBeChecked, 7, 7, 7, 0, 0, 71);
  //passphrase #2 - Clayton Loraine
  Song2.CalculateCombination(phraseToBeChecked, 10, 13, 1, 0, 0, 72);
  //passphrase #3 - Cameron Tanzyus
  Song3.CalculateCombination(phraseToBeChecked, 25, 10, 13, 16, 19, 73);

  //Those who helped us along the way
  //passphrase #4 - Peter Binder
  Song4.CalculateCombination(phraseToBeChecked, 1, 1, 19, 0, 0, 74);
  //passphrase #5 - Brett Barker
  Song5.CalculateCombination(phraseToBeChecked, 25, 10, 13, 16, 19, 75);

  //Other Secrets I threw in there for fun
  //None yet!
}
