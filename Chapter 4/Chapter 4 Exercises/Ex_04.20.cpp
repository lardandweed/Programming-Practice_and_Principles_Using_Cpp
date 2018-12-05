// record a list of names and scores; take a name and print corresponding score
#include "../../../std_lib_facilities.h"

void recordData(void);
void printScore(string);

vector<string> names;
vector<int> scores;
string nInput;
int sInput;
string key;

int main()
{
	recordData();
	cout << "\nEnter the name you want to check:\n";
	cin >> key;
	printScore(key);
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

void printScore(string input)
{
	bool found = false;
	
	for (int i = 0; i < names.size(); ++i)
		if (input == names[i]) {
			cout << names[i] << "'s score is " << scores[i] << "\n";
			found = true;
		}
	if (!found)
		cout << "Name not found\n";

	return;
}