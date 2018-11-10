// find prime numbers between 1 and 100
// consider '2' the first prime
#include "../../../std_lib_facilities.h"

constexpr int minNum = 3;		// start from '3' since '2' identified as first prime
constexpr int maxNum = 100;

int main()
{
	vector<int> pSet = { 2 };
	bool isPrime;

	for (int num = minNum; num <= maxNum; ++num) {
		isPrime = true;
		for (int prime:pSet)
			if (num%prime == 0) {
				isPrime = false;
				break;
			}
		if (isPrime == true)
			pSet.push_back(num);
	}
	cout << "List of primes between 1 and 100:\n";
	for (int printNum : pSet)
		cout << printNum << "\n";
}