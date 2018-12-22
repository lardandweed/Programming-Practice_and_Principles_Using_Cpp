/*
Bulls and Cows guessing game (repeatable)
guess a 4-digit number
Bull = correct digit in the correct position
Cow = correct digit in the wrong position
*/
// Avoiding use of global variables in this attempt

#include "../../../std_lib_facilities.h"

// Get input from user to seed random number generation
void get_seed()
{
	double input;
	
	cout << "Enter any number to generate a unique-4-digit answer:\n";
	while (!(cin >> input)) {
		cout << "Please enter a number:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	srand(input);
	return;
}

// Verify program generated a unique-4-digit answer; throw an error if not unique
// Required for game to proceed properly
void check_ans(vector<int> &ans)
{
	for (int i = 1; i < ans.size(); ++i)
		for (int j = 0; j < i; ++j)
			if (ans[i] == ans[j]) error("Answer was not generated correctly");
	return;
}

// Generate a unique-4-digit answer for users to guess
void gen_ans(vector<int> &ans)
{
	int digit;
	bool unique;
		
	ans[0] = randint(9);		// populate ans with 4 unique digits				
	for (int i = 1; i < ans.size(); ++i) {
		unique = false;
		while (!unique) {		// repeat with a new digit until a unique digit is found
			digit = randint(9);
			for (int j = 0; j < i; ++j) 
				if (digit == ans[j]) {
					unique = false;
					break;
				} else 
					unique = true;
			if (unique) ans[i] = digit;
		}
	}
	
	check_ans(ans);
	return;
}

// Check user entered a unique-4-digit number
bool check_guess(vector<int> &guess, string input)
{
	regex form("[[:digit:]]+");
	bool valid = true;

	if (input.size() == guess.size() && regex_match(input, form)) {
		for (int i = 0; i < guess.size() - 1; ++i)
			for (int j = i + 1; j < guess.size(); ++j)
				if (input[i] == input[j]) valid = false;
	} else 
		valid = false;

	return valid;
}

// Get a unique-4-digit number from user and load into guess
bool get_guess(vector<int> &guess)
{
	string input;
	bool valid = false;
		
	while (!valid) {					// Check input has valid format
		cout << "Please enter a postive integer with 4 unique digits (ctrl+z to quit):\n";
		cin >> input;
		if (cin.eof())		// Allow users to quit mid-program by entering ctrl-z
			return false;
		else 
			valid = check_guess(guess, input);
	}
	
	for (int i = 0; i < guess.size(); ++i)	// Load input into guess
		guess[i] = input[i] - '0';
	
	return true;
}

// Check if user guessed correctly (guess == ans)
bool check_correct(vector<int> &ans, vector<int> &guess)
{
	int bull = 0;
	int cow = 0;

	for (int i = 0; i < guess.size(); ++i)		// Check guess==ans
		for (int j = 0; j < ans.size(); ++j)
			if (guess[i] == ans[j] && i==j) 
				++bull;
			else if (guess[i] == ans[j]) 
				++cow;
	if (bull < 0 || bull > guess.size() || cow < 0 || cow > guess.size())
		error("Something went wrong with the calculations");
	
	cout << bull << " bull(s) and " << cow << " cow(s)\n";	// Print result
	if (bull == 4) {
		cout << "You guessed right!\n";
		return true;
	}
	else {
		cout << "Try again! ";
		return false;
	}
}

int main()
try {
	vector<int> ans(4);
	vector<int> guess(4);
	bool correct;
	bool cont = true;
	char input;

	get_seed();
	while (cont) {
		correct = false;
		gen_ans(ans);
		while (!correct) {
			cont = get_guess(guess);
			if (!cont) return 0;
			correct = check_correct(ans, guess);
		}
		
		cout << "Enter 'y' to play again; Enter any other key to quit:\n";
		cin >> input;
		if (input != 'y') cont = false;
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