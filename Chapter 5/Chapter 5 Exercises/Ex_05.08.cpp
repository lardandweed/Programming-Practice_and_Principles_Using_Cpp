// read and store series of integers; find sum of first N integers
/*
	only integer inputs will be stored
	non-integer inputs are ignored with a message
	integer inputs following non-integer inputs will also be stored
	stop taking input after the first '|'

	Example:
		2
		1 2 3.4 5a 
		bc -6| 0 7.9 a
	{2, 1, 2, -6} will be stored
	{3.4, 5a, bc} will be ignored with a message
*/
#include "../../../std_lib_facilities.h"

constexpr char stopkey = '|';
vector<int> numbers;

// get number of integers (n) to sum
int getn()			
{
	int n;
	
	cout << "Please enter the number of values you want to sum:\n";
	while (!(cin >> n) || n < 1) {
		cout << "Number of values must be at least 1. Please enter another number:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return n;
}

void check_int(string input)
/*
	check if input is an integer
	if yes, store in vector:numbers
	if no, ignore input with message
*/
{
	regex integer("-?[[:digit:]]+");
	
	if (regex_match(input, integer))
		numbers.push_back(stoi(input));
	else
		cout << "Entry '" << input << "' ignored: Not an integer\n";
	return;
}

bool check_stop(string input)
// check whether to stop retrieving values
{
	string trunc_input;

	for (int i = 0; i < input.size(); ++i)
		if (input[i] == stopkey) {
			/* 
				get string preceeding '|'
				for cases where users do not use a space before '|'; e.g. '32|'
			*/
			trunc_input = input.substr(0, i);
			if (trunc_input.size() > 0)		//no need to check_int if null string
				check_int(trunc_input);		
			return true;
		}
	return false;
}

void print_sum(int n)
//print the sum of first n values in vector:numbers
{
	int sum = 0;
	
	if (n > numbers.size())
		error("Number of values to sum is greater than number of legal values entered");
	else {
		cout << "The sum of the first " << n << " numbers ( ";
		for (int i = 0; i < n; ++i) {
			cout << numbers[i] << ' ';
			sum += numbers[i];
		}
		cout << ") is " << sum << '\n';
	}
	return;
}

int main()
try {
	int n = getn();
	string val;

	cout << "Please enter some integers (press '|' to stop):\n";
	while (cin >> val) {
		if (check_stop(val))
			break;
		else
			check_int(val);
	}
	print_sum(n);

	return 0;
}
catch (runtime_error& e) {
	cerr << "Error: " << e.what() << "\n";
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Error: Unknown exception\n";
	keep_window_open();
	return 2;
}