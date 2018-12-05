// record a list of names and scores; print names and scores
#include "../../../std_lib_facilities.h"

int main()
{
	vector<string> names;
	vector<int> scores;
	string nInput;
	int sInput;
	bool error = false;

	cout << "Enter a name and a score. Terminate input with 'NoName 0':\n";
	while ((cin >> nInput >> sInput) && (nInput != "NoName" || sInput != 0)) {
		for (string namecheck : names)
			if (namecheck == nInput) {
				cout << "Error: Name entered twice\n";
				error = true;
				break;
			}

		if (error)
			break;
		else {
			names.push_back(nInput);
			scores.push_back(sInput);
			cout << "Enter a name and a score. Terminate input with 'NoName 0':\n";
		}
	}

	cout << "\nList of names and scores entered:\n";
	for (int i = 0; i < names.size(); ++i)
		 cout << names[i] << '\t' << scores[i] << "\n";
}