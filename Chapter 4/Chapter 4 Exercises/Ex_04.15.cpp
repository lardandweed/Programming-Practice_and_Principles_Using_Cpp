// find the first N prime numbers (N is user defined)
#include "../../../std_lib_facilities.h"

int getNum();
bool checkPrime(int checkNum);

vector<int> primes{ 2 };

int main()
{
	int num = getNum();
	int current = 3;					// start search from 3
	bool found;

	cout << "\nThe first " << num << " prime numbers are:\n2 ";

	for (int i = 2; i <= num; ++i) {	// start finding 2nd prime number since 1st already known
		found = false;
		while (!found) {
			found = checkPrime(current);
			if (found == true) {
				primes.push_back(current);
				cout << current << " ";
			}
			++current;
		}
	}
}

int getNum()
{
	int input;

	cout << "How many prime numbers do you want to find?\n";
	while (!(cin >> input) || input < 1) {
		cout << "Mininum number is 1!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	return input;
}

bool checkPrime(int num)
{
	bool isPrime = true;
	
	for (int primefactor : primes)
		if (primefactor > (int)sqrt(num))
			break;
		else if (num%primefactor == 0) {
			isPrime = false;
			break;
		}
	
	return isPrime;
}