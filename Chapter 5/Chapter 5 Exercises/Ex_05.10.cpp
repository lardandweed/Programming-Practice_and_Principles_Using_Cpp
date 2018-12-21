// read and store series of numbers
// store and print the difference between adjacent numbers
#include "../../../std_lib_facilities.h"

vector<double> numbers;
vector<double> diffs;

void getnum()
{
	double input;

	cout << "Please enter some integers (enter any non-number to stop):\n";
	while (cin >> input) numbers.push_back(narrow_cast<double>(input));
	return;
}

void getdiff(int n)
{
	if (n < 2)		// check there were at least 2 numbers entered
		error("Less than 2 numbers entered");
	
	for (int i = 0; i < n - 1; ++i)
		diffs.push_back(abs(numbers[i + 1] - numbers[i]));
	return;
}

int main()
try {
	getnum();
	getdiff(numbers.size());

	for (int i = 0; i < diffs.size(); ++i)
		cout << "Difference between " << numbers[i] << " and " << numbers[i + 1] << " is " << diffs[i] << '\n';

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