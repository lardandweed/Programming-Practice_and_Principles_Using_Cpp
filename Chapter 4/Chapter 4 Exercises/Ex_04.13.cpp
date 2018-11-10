// Sieve of Eratosthenes; calculates prime numbers from between 1 - 100
#include "../../../std_lib_facilities.h"

void initialiseNumbers(int maxNumber);
void findPrimes(int limit);
void printPrimes();

vector<char> numbers;

int main()
{
	int max = 100;
	int maxFactor = sqrt(max);

	initialiseNumbers(max);
	findPrimes(maxFactor);
	cout << "The prime numbers between 1 and " << max << " are:\n";
	printPrimes();
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
	for (int i=0; i<numbers.size();++i)
		if (numbers[i] == 'y')
			cout << i+1 << " ";
	cout << "\n";

	return;
}