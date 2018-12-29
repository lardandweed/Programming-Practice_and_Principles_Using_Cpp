// Define a class Name_value that holds a string and a value.
// Rework exercise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors.
	
/*
	Write a program where you first enter a set of name-and-value pairs, 
	such as Joe 17 and Barbara 22. 
	Terminate input with NoName 0. 
	Check that each name is unique
	Terminate with an error message if a name is entered twice. 
	Write out all the (name,score) pairs, one per line.
*/
#include "../../../std_lib_facilities.h"

class Name_value {
public:
	Name_value(string n, double s):name(n),score(s) { }
	string name;
	double score;
};

int main()
try {
	vector<Name_value> entries;
	string name;
	double score;

	while (true) {
		cin >> name >> score;
		if (name == "NoName" && score == 0) break;
		if (!cin) {
			cout << "Invalid entry: ignored!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			for (Name_value entry : entries)
				if (name == entry.name) error("Name entered twice");
			entries.push_back(Name_value{ name,score });
		}
	}

	for (Name_value entry : entries)
		cout << entry.name << ' ' << entry.score << '\n';

	return 0;
}
catch (runtime_error& e) {
	cerr << "Error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Error: unknown exception\n";
	keep_window_open();
	return 2;
}