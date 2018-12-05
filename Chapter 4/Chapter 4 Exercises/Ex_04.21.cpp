// record a list of names and scores; take a score and print corresponding names
#include "../../../std_lib_facilities.h"

void recordData(void);
void printNames(int);

vector<string> names;
vector<int> scores;
string nInput;
int sInput;
int key;

int main()
{
	recordData();
	cout << "\nEnter the score you want to check:\n";
	cin >> key;
	printNames(key);
}

void recordData()
{
	bool error = false;

	cout << "Enter a name and a score. Terminate input with 'NoName 0':\n";
	while ((cin >> nInput >> sInput) && (nInput != "NoName" || sInput != 0)) {
		for (string nameCheck : names)
			if (nameCheck == nInput) {
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

	if (!cin) {
		cout << "Invalid entry. Input terminated\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return;
}

void printNames(int input)
{
	bool found = false;

	cout << "\nNames with a score of " << input << ":\n";
	for (int i = 0; i < scores.size(); ++i)
		if (input == scores[i]) {
			cout << names[i] << "\n";
			found = true;
		}

	if (!found)
		cout << "Score not found\n";

	return;
}