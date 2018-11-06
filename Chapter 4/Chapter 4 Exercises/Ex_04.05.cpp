// a simple calculator program
#include "../../../std_lib_facilities.h"

int main()
{
	double val1 = 0;
	double val2 = 0;
	char opr = ' ';

	cout << "Enter your first number:\n";
	cin >> val1;
	cout << "Enter your second number:\n";
	cin >> val2;
	while (opr != '+' && opr != '-' && opr != '*' && opr != '/') {
		cout << "Enter the operation you want to perform:\n";
		cin >> opr;
		if (opr != '+' && opr != '-' && opr != '*' && opr != '/')
			cout << "That is not a valid operator! ";
	}
	switch (opr) {
		case '+':
			cout << "The sum of " << val1 << " and " << val2 << " is " << val1 + val2 << ".\n";
			break;
		case '-':
			cout << "The difference between " << val1 << " and " << val2 << " is " << fabs(val1 - val2) << ".\n";
			break;
		case '*':
			cout << "The product of " << val1 << " and " << val2 << " is " << val1 * val2 << ".\n";
			break;
		case '/': 
			cout << "The quotient of " << val1 << " divided by " << val2 << " is " << val1 / val2 << ".\n";
			break;
		default:
			cout << "That operator got through my checks somehow!";
			break;
	}
}
