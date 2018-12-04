// Find the min, max, mode of a set of strings
#include "../../../std_lib_facilities.h"

int main()
{
	vector<string> strings;
	string input = "";
	string previous = "";
	string mode = "";
	int count = 0;
	int maxCount = 0;

	cout << "Please enter a set of strings; Enter ctrl+z to stop:\n";
	while (cin >> input)
		strings.push_back(input);

	sort(strings);
	for (string current : strings) {
		if (current == previous)
			++count;
		else
			count = 1;
		if (count > maxCount) {
			mode = current;
			maxCount = count;
		}
		previous = current;
	}

	cout << "min string = '" << strings[0] << "' | max string = '" << strings[strings.size()-1] << "'\n";
	cout << "mode = '" << mode << "' with " << maxCount << " appearances\n";
}