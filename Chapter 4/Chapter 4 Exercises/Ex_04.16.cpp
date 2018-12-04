// Find the mode of a set of postive integers
#include "../../../std_lib_facilities.h"

int main()
{
	vector<int> numbers;
	int previous = 0;
	int mode = 0;
	int count = 0;
	int max = 0;
	int input;

	cout << "Please enter a set of postive integers; Enter any non-integer to finish:\n";
	while (cin >> input)
		numbers.push_back(input);

	sort(numbers);
	for (int current : numbers) {
		if (current == previous)
			++count;
		else
			count = 1;
		if (count > max) {
			max = count;
			mode = current;
		}
		previous = current;
	}

	cout << "\nThe mode of the set is " << mode << " with " << max << " appearances.\n";
}