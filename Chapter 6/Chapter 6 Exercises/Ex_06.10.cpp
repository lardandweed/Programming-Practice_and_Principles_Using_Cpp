/*
Design a program that asks users for two numbers, 
asks them whether they want to calculate permutations or combinations, 
and prints out the result.
*/
#include "../../../std_lib_facilities.h"

int get_a()
{
	double a;

	cout << "Please enter a positive number(a) (decimals will be rounded down):\n";
	while (!(cin >> a) || a < 0) {
		cout << "Please enter a postive number:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	return int(a);
}

int get_b(int a)
{
	double b;

	cout << "Please enter a positive number(b) <= " << a << " (decimals will be rounded down):\n";
	while (!(cin >> b) || b < 0 || b > a) {
		cout << "Please enter a positive number <= " << a << ":\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return int(b);
}

char get_opt()
{
	char opt;

	cout << "Do you want to perform a combination or permutation (enter 'c'/'p')?\n";
	while (true) {
		cin >> opt;
		switch (opt) {
			case 'p': case 'P': case 'c': case 'C':
				return opt;
			default:
				cout << "Please enter either 'c' or 'p':\n";
				break;
		}
	}
}

int factorial(int n)
{
	int result = 1;

	if (n < 0)
		error("factorial of a negative number");
	else if (n == 0 || n == 1)
		return result;
	else 
		while (n > 1) {
			result *= n;
			n -= 1;
		}
	
	return result;
}

int permutation(int a, int b)
{
	if (a < b) error("a < b");
	int result = factorial(a) / factorial(a - b);

	return result;
}

int combination(int a, int b)
{
	if (a < b) error("a < b");
	int result = permutation(a,b) / factorial(b);

	return result;
}

int main()
try {
	char again = 'y';
	int result;
	
	while (again == 'y') {
		int a = get_a();
		int b = get_b(a);
		char opt = get_opt();

		switch (opt) {
			case 'p': case 'P':
				result = permutation(a, b);
				cout << "P(" << a << "," << b << ") = " << result << '\n';
				break;
			case 'c': case 'C':
				result = combination(a, b);
				cout << "C(" << a << "," << b << ") = " << result << '\n';
				break;
			default:
				error("Unknown option entered");
		}

		cout << "Again? (enter 'y' for again; anything else to quit)\n";
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
	cerr << "Error: unknown error\n";
	keep_window_open();
	return 2;
}