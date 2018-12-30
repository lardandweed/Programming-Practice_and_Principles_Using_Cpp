/* 
Write a program that reads digits and composes them into integers. 
For example, 123 is read as the characters 1, 2, and 3. 

The program should output 123 is 1 hundred and 2 tens and 3 ones. 
The number should be output as an int value. 

Handle numbers with one, two, three, or four digits.
*/
#include "../../../std_lib_facilities.h"

constexpr int LEN = 4;				// max length of input
constexpr int THOUSANDS = 0;		// vector position of digit representing thousands
constexpr int HUNDREDS = 1;			// vector position of digit representing hundreds
constexpr int TENS = 2;				// vector position of digit representing tens
constexpr int ONES = 3;				// vector position of digit representing ones

class digit {
public:
	char kind;
	int value;
	digit(char ch)
		:kind(ch), value(0) { }
	digit(char ch, int val)
		:kind(ch), value(val) { }
};

// check num is <= 4 digits long and contains only digits
bool check_num(string input)
{
	if (input.size() > LEN) return false;
	for (char digit : input)
		if (digit < '0' || digit > '9') return false;

	return true;
}

// get an input num from user
string get_input()
{
	bool valid = false;
	string input;

	while (!valid) {
		cout << "Please enter a series of digits (MAX 4 digits; no decimal point; no negatives):\n";
		cin >> input;
		valid = check_num(input);
	}

	return input;
}

// load the each digit of input into digits
// a valid digit will be loaded as an element of kind='#' and value=value of digit
void load_digits(vector<digit>& digits, string input)
{
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] < '0' || input[i] > '9') error("Digit expected");
		digits[LEN - input.size() + i] = digit('#', input[i] -'0');
	}
	return;
}

// prints the digit in the ones place
void ones(vector<digit> digits, bool add_and)
{
	digit d = digits[ONES];

	if (d.kind == '#' && d.value != 0) {
		if (add_and) cout << "and ";
		if (d.value == 1)
			cout << d.value << " one ";
		else
			cout << d.value << " ones ";
	}

	return;
}

// prints the digit in the tens place
// also returns true/false to set add_and for next function
bool tens(vector<digit> digits, bool add_and)
{
	digit d = digits[TENS];

	if (d.kind == '#' && d.value != 0) {
		if (add_and) cout << "and ";
		if (d.value == 1)
			cout << d.value << " ten ";
		else
			cout << d.value << " tens ";
	}
	else if (!add_and)
		return false;

	return true;
}

// prints the digit in the hundreds place
// also returns true/false to set add_and for next function
bool hundreds(vector<digit> digits, bool add_and)
{
	digit d = digits[HUNDREDS];

	if (d.kind == '#' && d.value != 0) {
		if (add_and) cout << "and ";
		if (d.value == 1) 
			cout << d.value << " hundred ";
		else 
			cout << d.value << " hundreds ";
	}
	else if (!add_and)
		return false;

	return true;
}

// prints the digit in the thousands place
// also returns true/false to set add_and for next function
bool thousands(vector<digit> digits)
{
	digit d = digits[THOUSANDS];

	if (d.kind == '#' && d.value != 0) {
		if (d.value == 1) 
			cout << d.value << " thousand ";
		else
			cout << d.value << " thousands ";
	} else 
		return false;

	return true;
}

int main()
try {
	vector<digit> digits(LEN, digit('!'));	// element of '!' kind means it is not a valid digit
	string input = get_input();
	
	load_digits(digits, input);
	
	// print parsed results
	cout << stoi(input) << " is ";
	bool add_and = thousands(digits);
	add_and = hundreds(digits, add_and);
	add_and = tens(digits, add_and);
	ones(digits, add_and);

	return 0;
}
catch (runtime_error& e) {
	cerr << "Error:" << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Error: Unknown exception\n";
	keep_window_open();
	return 2;
}