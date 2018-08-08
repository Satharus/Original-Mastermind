#ifndef MASTERMIND_CLASSES_H
#define MASTERMIND_CLASSES_H

#include <iostream> //Included for the basic IO functionality.
#include <string> //Included for string functions.
#include <cstdlib> //Included for rand().
#include <ctime> //Included to allow the program to have more true randomness.
#include <iomanip> //Included for basic IO manipulation.
#define endl '\n' //Overriding "endl" with the ASCII character '\n' to prevent flushing the stream every time the program prints a new line.

//Using only specific functions/keywords from the std namespace.
using std::cin;
using std::cout;
using std::string;
using std::setw;

namespace mastermind //Creating a namespace to contain the classes.
{
	 class Code //A class for the any code in the program, such as the guesses, hidden code, and results.
	 {
	 private:
		  string code;
	 public:
		  Code();
		  explicit Code(string &s);
		  void set(string &s);
		  string value();
	 };

	 class Board // A class that contains the board, the results, and the functions to play.
	 {
	 private:
		  char board[10][5];
		  string results[10];
		  Code code, guess, result;
	 public:
	 	 //Check each function's definition in classes.cpp to see what it does.
		  Board();

		  void print();

		  void placeData();

		  void compareGuess();

		  bool checkForRepetitions(string &);

		  void inputAndCheckCode(string &s);

		  void inputAndCheckCodeCustom(string &s);

		  void inputGuess();

		  void setCode();

		  void setCode(string s);

		  void initialiseGame();

		  void play();
	 };
}

#endif //MASTERMIND_CLASSES_H