// find prime numbers from 1 to user-defined max
// '2' identified as first prime
#include "../../../std_lib_facilities.h"

constexpr int minNum = 3;		// start from '3' since '2' identified as first prime

int main()
{
	vector<int> pSet = { 2 };
	bool isPrime;
	int maxNum;

	cout << "Enter a max limit to calculate primes: ";
	cin >> maxNum;

	for (int num = minNum; num <= maxNum; ++num) {
		for (int prime : pSet)
			if (num%prime == 0) {
				isPrime = false;
				break;
			} else
				isPrime = true;
		if (isPrime)
			pSet.push_back(num);
	}
	cout << "List of primes from 1 to " << maxNum << ":\n";
	for (int printNum : pSet)
		cout << printNum << "\n";
}