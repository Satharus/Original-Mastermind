#include "classes.h"

int gTurn(-1); //Global variable used to count the turns of the game.
string empty; //Global empty string to be passed to constructors.

///////////////////////// CODE CLASSS ////////////////////////////////////////////

mastermind::Code::Code(): code{"0B0W"} { } //Default constructor (for the result).

mastermind::Code::Code(string &s): code{s} { } //Default single-argument constructor that sets the code to the passed string.

void mastermind::Code::set(string &s)
{
	//Sets the code to the passed string.
	code = s;
}

string mastermind::Code::value()
{
	//Returns the value of the code.
	return code;
}

//////////////////////////////////////////////////////////////////////////////////


///////////////////////// BOARD CLASSS ///////////////////////////////////////////

mastermind::Board::Board() : board{}, code(empty), guess(empty), result()
{
	//Default constructor for the board, initialises all of the codes as empty strings
	//and initialises the board to a 2D array of the character 'O'.
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 4; j++)
			board[i][j] = 'O';
}

void mastermind::Board::print()
{
	//Prints the board with the respective result next to every row.
	system("clear");
	results[gTurn] = result.value();
	cout << "\tBOARD" << "\t\t       " << "RESULTS" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << setw(5) << i + 1 << " | ";

		for (int j = 0; j < 4; j++)
			cout  << board[i][j] << ' ';

		cout << "\t\t";
		cout << results[i];
		cout << endl;
	}
}

void mastermind::Board::placeData()
{
	//Places the player's guess onto the board.
	for (int i = 0; i < 4; i++)
		board[gTurn][i] = guess.value()[i];

}

void mastermind::Board::compareGuess()
{
	//Compares the player's guess to the hidden code, and sets the result to a string in the form of "XBYW"
	//where (B)lack means that the colour is correct and is in place,
	//(W)hite means that the colour is correct but isn't in place,
	//and X and Y are both integers indicating the amount of their respective colours.
	int black(0), white(0);
	string dummy, _guess = guess.value(), _code = code.value();

	if (_guess == _code)  dummy = "4B0W";

	else
	{
		for (int i = 0; i < 4; i++)
		{
			unsigned long index = _code.find(_guess[i]);

			if (_guess[i] != _code[i])
			{
				if (index != string::npos && _guess[index] == _code[index])
				{
					black++;
					_code[index] = '#';
				}

				else if (index != string::npos && _guess[index] != _code[index])
				{
					white++;
					_code[index] = '#';
				}
			}

			else
			{
				black++;
				_code[index] = '#';
			}
		}

		dummy+= (char) (black + '0');
		dummy+= 'B';
		dummy+=  (char) (white + '0');
		dummy+= 'W';
	}

	result.set(dummy);
}

bool mastermind::Board::checkForRepetitions(string &s)
{
	//Checks if the 4 character code to be set has any repeated colours.
	bool repeat = false;
	for (int i = 0; i < 4; i++)
		for (int j = i+1; j < 4; j++)
			if (s[i] == s[j])
				repeat = true;

	return !repeat;
}

void mastermind::Board::inputAndCheckCode(string &s)
{
	//Takes a string s, lets the user input its value, and then checks the validity of its length and the colours in it.
	while (true)
	{
		bool validColours[4] = {}, valid(true);
		cin >> s;

		for (int i = 0; i < s.size(); i++)
			if (s[i] > 96 && s[i] < 123) s[i]-=32;

		if (s.size() != 4)
		{
			cout << "Invalid length" << endl;
			continue;
		}

		else
		{
			for (int i = 0; i < 4; i++)
			{
				if (s[i] == 'R' ||
					 s[i] ==	'G' ||
					 s[i] ==	'B' ||
					 s[i] ==	'Y' ||
					 s[i] == 'P' ||
					 s[i] == 'W' ||
					 s[i] == 'C' ||
					 s[i] ==	'M')
					validColours[i] = true;
			}

			for (int i = 0; i < 4; i++)
				if (!validColours[i])
						valid = false;

			if (!valid) cout << "Invalid colours" << endl;
			else break;
			}
	}
}

void mastermind::Board::inputAndCheckCodeCustom(string &s)
{
	//A function that inputs a custom code, and checks that it doesn't have any repetitions.
	while (true)
	{
		inputAndCheckCode(s);
		if(checkForRepetitions(s))
		{
			setCode(s);
			break;
		}
		else cout << "Original mastermind forbids the repetition of colours." << endl;
	}
}

void mastermind::Board::inputGuess()
{
	//Inputs the guess from the user, bumps gTurn, and makes sure that the user enters a valid code.
//	cout << "Code: " << code.value() << endl; //For testing only, shouldn't ever be visible to the player.
	cout << "Available colours: (R)ed, (G)reen, (B)lue, (Y)ellow\n" <<
	"\t\t   (P)ink, (W)hite, (C)yan, (M)agenta"<< endl;

	cout << "Enter the guessed code: ";

	string s;
	inputAndCheckCode(s);

	guess.set(s);
	gTurn++;
}

void mastermind::Board::setCode()
{
	//Sets the hidden code by randomising it.
	srand((unsigned int)time(nullptr));
	string randomCode;
	char colours[9] = {'R', 'G', 'B', 'Y', 'P', 'W', 'C', 'M'}; //Character array contains the colours Red, Green, Blue, Yellow, Pink, White, Cyan, Magenta

	for (int i = 0; i < 4; i++)
	{
		int x = rand() % 8;
		if (randomCode.find(colours[x]) == string::npos)
		{
			randomCode += colours[x];
		}
		else i--;
	}
	code.set(randomCode);
}

void mastermind::Board::setCode(string s)
{
	//Sets the hidden code to the given string s.
	code.set(s);
}

void mastermind::Board::initialiseGame()
{
	//Initialises the game CLI to the user, and then asks which mode they want to play.
	cout << "\t\t\t   Welcome to MasterMind!" << endl;
	cout << "Choose the mode you want to play:" << endl;
	cout << "1- Singleplayer - Random-generated code" << endl
		  << "2- Two-Player - One player sets the code" << endl;
	retry:
	int choice;
	cin >> choice;

	switch(choice)
	{
		case 1:
		{
			setCode();
			break;
		}

		case 2:
		{
			cout << "Enter the hidden code: ";
			string customCode;
			inputAndCheckCodeCustom(customCode);
			system("clear"), system("clear");
			break;
		}

		default:
			cout << "Invalid input! Please try again: ";
			goto retry;
	}
}

void mastermind::Board::play()
{
	//Plays the game lol
	initialiseGame();

	while (true)
	{
		inputGuess();
		compareGuess();
		placeData();
		print();

		if (result.value() == "4B0W")
		{
			cout << "You Win!" << endl << "It took you " << gTurn + 1 << " trie(s)" << endl;
			break;
		}

		if (gTurn > 8)
		{
			cout << "You Lose!" << endl << "The code was " << code.value() << endl;
			break;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////
