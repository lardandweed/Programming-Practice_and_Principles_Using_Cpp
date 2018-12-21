// read and store series of integers; find sum of first N integers
// give error message if sum cannot be represented as an int
#include "../../../std_lib_facilities.h"

vector<int> numbers;

int getn()
{
	double n;
	cout << "Enter the number of values you want to sum:\n";
	while (!(cin >> n) || floor(n) != ceil(n) || n < 1) {
		cout << "Please enter an integer greater than 0:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return int(n);
}

void getnum()
{
	double input;

	cout << "Please enter some integers (enter any non-number to stop):\n";
	while (cin >> input) numbers.push_back(narrow_cast<int>(input));
	return;
}

int findsum(int n)
{
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		if ((numbers[i] < 0) && (INT_MIN - numbers[i] > sum))
			error("Sum of numbers cannot be expressed as an integer");
		else if ((numbers[i] > 0) && (INT_MAX - numbers[i] < sum))
			error("Sum of numbers cannot be expressed as an integer");
		else
			sum += numbers[i];
	}
	return sum;
}

void printsum(int n)
{
	int sum;

	if (numbers.size() < n)
		error("Not enough numbers to sum!");
	else
		sum = findsum(n);
	cout << "Sum of the first " << n << " integers is " << sum << '\n';
	return;
}

int main()
try {
	int n = getn();
	getnum();
	printsum(n);

	return 0;
}
catch (runtime_error& e) {
	cerr << "Error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Error: Unknown exception" << '\n';
	keep_window_open();
	return 2;
}