/*
Redo the “Bulls and Cows” game from exercise 12 in Chapter 5 to use
four letters rather than four digits.

To keep it simple, we will use lower-case letter only.
*/

/*
Chapter 5: Exercise 12
Implement a little guessing game called (for some obscure reason) “Bulls
and Cows.” The program has a vector of four different integers in the
range 0 to 9 (e.g., 1234 but not 1122) and it is the user’s task to discover
those numbers by repeated guesses. Say the number to be guessed is 1234
and the user guesses 1359; the response should be “1 bull and 1 cow”
because the user got one digit (1) right and in the right position (a bull)
and one digit (3) right but in the wrong position (a cow). The guessing
continues until the user gets four bulls, that is, has the four digits correct
and in the correct order.
*/
#include "../../../std_lib_facilities.h"

constexpr int LEN = 4;				// character length of answer
const string QUIT = "quitgame";		

// get user to input a seed for srand()
int get_seed()
{
	int seed;

	cout << "Please enter a number to generate a random answer:\n";
	while (!(cin >> seed)) {
		cout << "Please enter a number:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	return seed;
}

string gen_ans(int seed)
{
	string ans = "";
	char ch;
	bool unique;

	srand(seed);
	ans += (rand()%26) + 97;
	for (int i = 1; i < LEN; ++i) {
		unique = false;
		while (!unique) {
			ch = (rand() % 26) + 97;
			for (int j = 0; j < i; ++j) {
				if (ch == ans[j]) {
					unique = false;
					break;
				}
				else
					unique = true;
			}
		}
		ans += ch;
	}

	return ans;
}

string get_guess()
{
	string guess;
	bool valid = false;

	while (!valid) {
		cout << "Please enter a string with 4 unique lower-case letters (ctrl+z to stop):\n";
		cin >> guess;

		if (cin.eof()) return QUIT;

		// check for valid input
		if (guess.size() == LEN) valid = true;		// check guess is 4 characters long
		if (valid)		// proceed to check all letters if passed previous test
			for (char ch : guess)
				if (ch < 'a' || ch > 'z') {
					valid = false;
					break;
				}
		if (valid)		// proceed to check all unique if passed previous test
			for (int i = 0; i < LEN - 1; ++i) {
				for (int j = i + 1; j < LEN; ++j)
					if (guess[i] == guess[j]) {
						valid = false;
						break;
					}
				if (!valid) break;
			}
	}
	
	return guess;
}

bool check_guess(string& ans, string& guess, int& bull, int& cow)
{
	bull = cow = 0;
	
	for (int i = 0; i < LEN; ++i)
		for (int j = 0; j < LEN; ++j)
			if ((ans[i]) == guess[j])
				if (i == j)
					++bull;
				else
					++cow;
	
	if (bull == 4)
		return true;
	else
		return false;
}

int main() 
try {
	char again = 'y';
	int seed;
	string ans;
	string guess;
	int bull;
	int cow;
	bool correct;

	while (again == 'y') {
		correct = false;
		seed = get_seed();
		ans = gen_ans(seed);
		
		while (!correct) {
			guess = get_guess();
			if (guess == QUIT) return 0;
			correct = check_guess(ans, guess, bull, cow);

			cout << "You got " << bull << " bull(s) and " << cow << " cow(s).\n";
			if (correct) cout << "You guess right!\n\n";
		}

		cout << "Play again? (enter 'y' to play again, anything else to quit):\n";
		cin >> again;
	}

	return 0;
}
catch (runtime_error& e) {
	cerr << "Error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Error: Unknown exception\n";
	keep_window_open();
	return 2;
}