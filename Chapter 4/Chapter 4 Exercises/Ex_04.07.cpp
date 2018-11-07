// calculator that accepts only digits in word or numerical form
#include "../../../std_lib_facilities.h"

vector<string> wDigit;
vector<string> nDigit;

int inputCheck(string inputvalue);

// Initialise an array of digits in word form
void initialiseWordDigits()
{
	wDigit.push_back("zero");
	wDigit.push_back("one");
	wDigit.push_back("two");
	wDigit.push_back("three");
	wDigit.push_back("four");
	wDigit.push_back("five");
	wDigit.push_back("six");
	wDigit.push_back("seven");
	wDigit.push_back("eight");
	wDigit.push_back("nine");
}

// Initialise an array of digits in numerical form
void initialiseNumberDigits()
{
	for (int i = 0; i < wDigit.size(); ++i)
		nDigit.push_back(to_string(i));
}

int main()
{
	initialiseWordDigits();
	initialiseNumberDigits();

	string val1 = "?";
	string val2 = "?";
	char opr = '?';
	double num1;
	double num2;

	while (1) {										// request user input for first digit			
		cout << "Enter the first digit (spelled or numerical):\n";
		cin >> val1;
		if ( (num1=inputCheck(val1)) == wDigit.size() )		// call function inputCheck() to check if input is a digit
			cout << "That is not a digit! ";
		else 
			break;
	}

	while (1) {										// request user input for second digit
		cout << "Enter the second digit (spelled or numerical):\n";
		cin >> val2;
		if ( (num2=inputCheck(val2)) == wDigit.size() )		// call function inputCheck() to check if input is a digit
			cout << "That is not a digit! ";
		else
			break;
	}

	while (1) {										// request user input for operator
		cout << "Enter an operator:\n";
		cin >> opr;
		if (opr == '+' || opr == '-' || opr == '*' || opr == '/')
			break;
		else
			cout << "That is not a valid operator! ";
	}

	switch (opr) {									// calculate and print results
		case '+':
			cout << "The sum of " << num1 << " and " << num2 << " is " << num1 + num2 << ".\n";
			break;
		case '-':
			cout << "The difference between " << num1 << " and " << num2 << " is " << fabs(num1 - num2) << ".\n";
			break;
		case '*':
			cout << "The product of " << num1 << " and " << num2 << " is " << num1 * num2 << ".\n";
			break;
		case '/':
			cout << "The quotient of " << num1 << "/" << num2 << " is " << num1 / num2 << ".\n";
			break;
		default:
			cout << "Hmm... something strange going on here.\n";
			break;
	}
}

// checks if input is a digit; returns value of digit
int inputCheck(string input) 
{
	int i;
	for (i = 0; i < wDigit.size(); ++i)
		if (input == wDigit[i] || input == nDigit[i])
			break;
	return i;
}