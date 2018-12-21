// print the first N numbers of the Fibonnaci sequence
// print the largest Fibonnaci number that fits in an int
#include "../../../std_lib_facilities.h"

vector<int> fibonacci;
int current = 1;
int previous = 0;
int prevprev = 0;

void loadfib()
{
	while (INT_MAX - previous >= prevprev) {
		fibonacci.push_back(current);
		prevprev = previous;
		previous = current;
		current = prevprev + previous;
	}
}

int getn()
{
	double n;
	
	cout << "How many Fibonacci numbers do you want to print?\n";
	while (!(cin >> n) || floor(n) != ceil(n) || n < 1) {
		cout << "Please enter an integer greater than 0:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return int(n);
}

int main()
try {
	loadfib();
	
	int n = getn();
	if (n > fibonacci.size())
		error("Cannot print so many numbers. Later numbers exceed max limit of int.");
	else {
		cout << "The first " << n << " numbers of the Fibonacci sequence are:\n";
		for (int i=0; i<n;++i)
			cout << fibonacci[i] << ' ';
	}
	cout << "\nThe largest Fibonacci number that fits in an int is " << fibonacci.back();
	
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