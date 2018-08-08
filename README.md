# Original Mastermind

### About

Original Mastermind is a board game that originated from the 1970s, created by Mordecai Meirowitz. 


It is a code-breaking game made for 2 players. Where player A sets a code and player B tries to deduce it by trial and error based on the feedback from player A.


### Gameplay

The game goes as follows:
+ Player A sets a hidden code once at the start of the game
+ Player B guesses the code
+ Player A provides player B with feedback
+ Player B deduces or supposes the next guess based on that feedback

This goes on for 10 turns or until player B guesses the code correctly.

### The Codes and the Feedback

#### The Codes
The code consists of 4 characters(colours) and each character is unique. 

The available colours are: (R)ed, (G)reen, (B)lue, (Y)ellow, (P)ink, (W)hite, (C)yan, and (M)agenta.

###### Examples:
+ RGBY
+ CMWP
+ BGYP

#### Feedback
The feedback is given in the format of XBZW, where X and Z are both integers referring to the number of black and white pegs respectively.

+ A black peg means that a character in the guessed code is present in the set code and is in its correct place.
+ A white peg means that a character in the guessed code is present in the set code but isn't in its correct place.

+ So, 0B4W means that player B has gotten all of the colours right but not in the correct order.
+ Also, 3B0W means that player B has 3 characters correct and in their right places but has one character wrong.

###### Example:
+ Set code:................RGYB
+ Guessed Code:.....RBGC
+ Feedback:..............1B2W
+ Player B gets 1 black peg because the character 'R' is correct, and 2 white pegs because 'B' and 'G' exist in the set code but they're not in the correct order. Hee gets nothing for the 'C' as it isn't present in the set code at all. Hence, getting 3 feedback pegs only instead of 4.

**Note:** 1B2W doesn't mean that the first character gets a black peg and the 2 characters after it get white pegs. The feedback isn't ordered.

### How to run

You can run this minigame using any GNU-C++ (g++) compiler that supports C++ 2011.

To run from a Linux shell:
+ Clone this repo, open a terminal in its folder and then run:
``` 
    g++ -std=c++11 classes.* main.cpp -o Mastermind #This compiles the files
    ./Mastermind #Thie runs the executable
```
