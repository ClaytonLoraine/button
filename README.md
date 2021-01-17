# Button

Using a single button, this code can create mutliple options based on how long and how many times and for how long it is pressed

This code is meant to be used with an AR-200R audio recorder. This code is able to play preset phrases on the AR-200R when set to binary mode and when ran by an arduino with 8 relays set up to send ground voltage to pins in the back of the AR-200R.


  Note 1: on most Arduinos there is already an LED on the board
  attached to pin 13.
  Note 2: In this circuit, when the button is pressed, Ground Voltage is what will be applied.

  by Clayton Loraine

  Uses snippets of code by Scuba Steve, Michael James, and J. Cameron Privett


Here is an overly complicated description/pseudocode for this, written more like a paper than anything else.

# Button code explanation

This code counts the number of clicks in a row that have been pressed within a certain amount of time and how long the last click was held. It then translates that to a phrase number (the song number to be played on the AR-200R) using this calculation:

phrase = (clicks * 3) + 1

IMPORTANT: “clicks” starts at 0 so it will always be one below the actual number of clicks.

After this calculation, a 1 or 2 is added to the phrase number depending on how long it was held for. There are only 3 possible phrases per click, depending on how long it is held. I call these a short press, a medium press, and a long press. An example of a short press is if the button is just pressed three times in quick succession and it isn’t held, it would come out to (2 * 3) + 1 which equals 7. So it would play phrase number 7. 

The time to activate the next two stages, medium and long, can be changed with the mediumPressMs and longPressMs variables. By default they are 2000, and 6000 respectively. shortPressMs is used to keep track of how long it takes between clicks to consider a click a double-click. It’s only 600 but if a person presses the button 3 times then holds for 1999 ms it will still be considered a “short click”. Once it’s held for 2000 ms, it becomes a medium length press, then when it is held until 6000 ms passes, it will become a long press. If the click is let go while it’s considered a medium press, it will add one to the phrase number. This will make the phrase number 8. If it is considered a long press, 2 will be added to the phrase number instead, making it 9. 

Once the phrase to play has been selected, it is sent to the ActivatePhrase function with decides what to do with it. The majority of phrases will move on to the next stage (playing the phrase) but some are different. First, it checks if the calculated phrase is 13, 14, or 15 (5 clicks, short, medium, or long press) it then send the signal to activate the pin number that is denoted by the “stopPin” variable. In this case, it’s 12. This should be connected to the relay attached to the pin that will stop the phrase being played. This way if someone presses the wrong song they can change it. 

If the phrase chosen is not 13, 14, or 15, it checks if the song that is about to play is supposed to be played or not. It does this by comparing the phrase number to the array of hidden phrases. More about this in the Easter Eggs section. If it’s one of the secret songs and is about to play but isn’t supposed to, this stops it from playing. This stops a person from playing a secret song just by knowing the phrase number, not by knowing the code. Again, more in Easter Eggs.

Finally, the phrase number goes through one final check. This is the RickRoll check. Every time a phrase is played, there is a 1 in 100 chance that it swaps the selected phrase for phrase 70, which on this device is “Never Gonna Give You Up” by Rick Astley. 

Once a phrase has been chosen, it runs a for loop that calculates the binary number for that chosen phrase number and outputs it up to 8 digits. It may be noted that the number outputted is backwards. This is done intentionally as the wires will be going over the Arduino backwards to save space, inverting the characters from the viewpoint of the Arduino, but they will be correct to the AR-200R. 

It then sends the signal through the 8 pins numbered in the “binaryPins” array along with sending a signal to the “start” pin. It outputs the phrase played, and resets the pins after a number of ms equal to the binaryDelay integer. It also resets the number of clicks so it is prepared for the next round.

# Easter Eggs
As mentioned before, there are Easter Eggs hard-coded in the form of “passcodes” or “passphrases”. Of course an Easter egg could be easily added just by putting a song connected to an odd phrase that someone would have to guess but these could be easily brute forced. Using passcodes, there is a must lower chance that someone will guess the code to get to the Easter egg song. Here’s how passcodes work.

Every time a phrase is played, it checks to see if it is the first digit in a passcode. If that is the case, the passcode is considered “active”. The next phrase that is played is then checked to see if it matches any of the next phrases within a passcode and so on until either the 5th phrase is hit or a 0 is placed within a passcode, cutting it short. If a phrase is played that is not a part of an active passcode then all active passcodes are inactivated. This way, the only way for a secret song to be played is by playing the correct phrases in the correct order. This can be done during the playing of a different phrase and it will override the currently playing phrase if successful. 

At the bottom of the Easter eggs file, there is a function called “CheckSecrets” that contains the objects for each passcode. They are laid out like this:

ObjectName.CalculateCombination(phrase to be checked, first digit of code, second digit, third, fourth, fifth, phrase to play when code is successful)

To stop the code short, just place zeros in the remaining slots.

For instance, this is the one that I added for myself:

Song2.CalculateCombination(phrase, 10, 13, 1, 0, 0, 72);

The button needs to be pressed 4 times than 5 than 1 time and then it will play phrase 72. When adding to this, be sure that the phrase you have selected to use for this is in the hiddenPhrases array located at the top of the ActivatePhrases function. This way someone can’t just cheat the system and press the button 24 times then hold it for a long press which would equal ((23 * 3) + 1) + 2 or phrase number 72.
