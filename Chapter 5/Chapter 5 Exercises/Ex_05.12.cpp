/* 
Bulls and Cows guessing game
guess a 4-digit number
Bull = correct digit in the correct position
Cow = correct digit in the wrong position
*/
#include "../../../std_lib_facilities.h"

const vector<int> ANS{1, 7, 0, 4};
vector<int> guess(4);
int bull = 0;
int cow = 0;

bool check_input(string input)
{
	regex form("[[:digit:]]+");
	bool valid = false;
	
	if (input.size() == guess.size() && regex_match(input, form)) {
		valid = true;
		for (int i = 0; i < guess.size() - 1; ++i)
			for (int j = i + 1; j < guess.size(); ++j)
				if (input[i] == input[j])
					valid = false;
	}
	return valid;
}

void getguess()
{
	string input;
	bool valid = false;

	// Check input has valid format
	while (!valid) {
		cout << "Please enter a postive integer with 4 unique digits:\n";
		cin >> input;
		valid = check_input(input);
	}
	// Load input into guess
	for (int i = 0; i < guess.size(); ++i)
		guess[i] = input[i] - '0';
	
	return;
}

bool checkguess()
{
	for (int i = 0; i < guess.size(); ++i)
		for (int j = 0; j < ANS.size(); ++j)
			if (guess[i] == ANS[j])
				if (i == j)
					++bull;
				else
					++cow;
	cout << bull << " bull(s) and " << cow << " cow(s)\n";
	
	if (bull == 4) {
		cout << "You guessed right!\n";
		return true;
	} else {
		cout << "Try again! ";
		return false;
	}	
}

int main()
try {
	bool correct = false;
	
	cout << "Guess what number I'm thinking.\n";
	while (!correct) {
		bull = cow = 0;
		getguess();
		correct = checkguess();
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