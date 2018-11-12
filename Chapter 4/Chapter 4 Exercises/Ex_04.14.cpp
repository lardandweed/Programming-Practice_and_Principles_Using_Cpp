// Sieve of Eratosthenes; calculates prime numbers from between 1 - user-input max
#include "../../../std_lib_facilities.h"

int getMax();
void initialiseNumbers(int maxNumber);
void findPrimes(int limit);
void printPrimes();

vector<char> numbers;

int main()
{
	int max = getMax();
	int maxFactor = sqrt(max);

	initialiseNumbers(max);
	findPrimes(maxFactor);
	cout << "\nThe prime numbers between 1 and " << max << " are:\n";
	printPrimes();
}

int getMax()
{
	int input;
	
	cout << "Find prime numbers from 1 to ___ (Enter an integer):\n";
	while (!(cin >> input) || input <= 1) {
		cout << "That is not a valid input. Please enter an integer greater than 1:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
			
	return input;
}

void initialiseNumbers(int maxNumber)
{
	numbers.push_back('n');
	for (int i = 1; i < maxNumber; ++i)
		numbers.push_back('y');

	return;
}

void findPrimes(int limit)
{
	for (int i = 0; i < limit; ++i)
		if (numbers[i] == 'y')
			for (int j = i + 1; j < numbers.size(); ++j)
				if ((j + 1) % (i + 1) == 0)
					numbers[j] = 'n';

	return;
}

void printPrimes()
{
	for (int i = 0; i < numbers.size(); ++i)
		if (numbers[i] == 'y')
			cout << i + 1 << " ";
	cout << "\n";

	return;
}
