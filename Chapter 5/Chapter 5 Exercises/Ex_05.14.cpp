/*
Read (day-of-the-week,value) pairs from standard input. 
Collect all the values for each day of the week in a vector<int> . 
Write out the values of the seven day-of-the-week vectors. 
Print out the sum of the values in each vector . 

Ignore illegal days of the week, such as Funday,
but accept common synonyms such as Mon and monday . 
Write out the number of rejected values.
*/
/*
Assumption:
The question requires taking each input in day-value format.

So the program will not ask for day and value seperately, e.g.:
	"Enter a day:"
	"Enter a value:"

Also extra values supplied by user will be ignored, e.g:
	"Monday 23 Tuesday"
If the above is supplied, 'Tuesday' will be ignored
*/
#include "../../../std_lib_facilities.h"

// Get a day and value from user input
bool get_input(string &day, string &val)
{
	cout << "Enter a day and a value (ctrl+z to stop):\n";
	cin >> day >> val;
	if (cin.eof()) return false;
				
	cin.clear();	// clear cin so extra inputs will not be supplied to next get_input();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return true;
}

// Check day is in acceptable format; prints a message if unacceptable
bool check_day(string day, vector<string> ok_days)
{
	for (string s : ok_days)
		if (day == s) return true;

	cout << "Illegal day ignored\n";
	return false;
}

// Check val is an integer; prints a message if not an integer
bool check_val(string val, int &reject)
{
	bool valid = true;

	if (val.size() == 1 && (val[0] < '0' || val[0] > '9'))		
		valid = false;
	else if (val[0] == '-') {
		for (int i = 1; i < val.size(); ++i)
			if (val[i] < '0' || val[i] > '9')
				valid = false;
	} else
		for (int i = 0; i < val.size(); ++i)
			if (val[i] < '0' || val[i] > '9')
				valid = false;
	
	if (!valid) {
		cout << "Illegal value rejected\n";
		++reject;
	}
	return valid;
}

// input values in their corresponding day-vectors
void update_day(string day, string val, vector<int> &mon, vector<int> &tue, vector<int> &wed, vector<int> &thur, vector<int> &fri, vector<int> &sat, vector<int> &sun)
{
	int inted_val = stoi(val);

	if (day == "Mon" || day == "mon" || day == "Monday" || day == "monday")
		mon.push_back(inted_val);
	else if (day == "Tue" || day == "tue" || day == "Tues" || day == "tues" || day == "Tuesday" || day == "tuesday")
		tue.push_back(inted_val);
	else if (day == "Wed" || day == "wed" || day == "Wednesday" || day == "wednesday")
		wed.push_back(inted_val);
	else if (day == "Thur" || day == "thur" || day == "Thurs" || day == "thurs" || day == "Thursday" || day == "thursday")
		thur.push_back(inted_val);
	else if (day == "Fri" || day == "fri" || day == "Friday" || day == "friday")
		fri.push_back(inted_val);
	else if (day == "Sat" || day == "sat" || day == "Saturday" || day == "saturday")
		sat.push_back(inted_val);
	else if (day == "Sun" || day == "sun" || day == "Sunday" || day == "sunday")
		sun.push_back(inted_val);
	else
		error("An illegal day was erroneously accepted");
}

// Print values entered for each day; print sum of values for each day
// Print number of rejected values
void print_vals(vector<int> mon, vector<int> tue, vector<int> wed, vector<int> thur, vector<int> fri, vector<int> sat, vector<int> sun, int reject)
{
	int sum;

	if (mon.size() > 0) {
		cout << "Values entered for Mon:\t ";
		sum = 0;
		for (int x : mon) {
			sum += x;
			cout << x << ' ';
		}
		cout << "SUM=" << sum << '\n';
	}
	else
		cout << "Values entered for Mon:\t NONE\n";

	if (tue.size() > 0) {
		cout << "Values entered for Tue:\t ";
		sum = 0;
		for (int x : tue) {
			sum += x;
			cout << x << ' ';
		}
		cout << "SUM=" << sum << '\n';
	}
	else
		cout << "Values entered for Tue:\t NONE\n";

	if (wed.size() > 0) {
		cout << "Values entered for Wed:\t ";
		sum = 0;
		for (int x : wed) {
			sum += x;
			cout << x << ' ';
		}
		cout << "SUM=" << sum << '\n';
	}
	else
		cout << "Values entered for Wed:\t NONE\n";

	if (thur.size() > 0) {
		cout << "Values entered for Thur: ";
		sum = 0;
		for (int x : thur) {
			sum += x;
			cout << x << ' ';
		}
		cout << "SUM=" << sum << '\n';
	}
	else
		cout << "Values entered for Thur: NONE\n";

	if (fri.size() > 0) {
		cout << "Values entered for Fri:\t ";
		sum = 0;
		for (int x : fri) {
			sum += x;
			cout << x << ' ';
		}
		cout << "SUM=" << sum << '\n';
	}
	else
		cout << "Values entered for Fri:\t NONE\n";

	if (sat.size() > 0) {
		cout << "Values entered for Sat:\t ";
		sum = 0;
		for (int x : sat) {
			sum += x;
			cout << x << ' ';
		}
		cout << "SUM=" << sum << '\n';
	}
	else
		cout << "Values entered for Sat:\t NONE\n";

	if (sun.size() > 0) {
		cout << "Values entered for Sun:\t ";
		sum = 0;
		for (int x : sun) {
			sum += x;
			cout << x << ' ';
		}
		cout << "SUM=" << sum << '\n';
	}
	else
		cout << "Values entered for Sun:\t NONE\n";

	cout << "Number of rejected values: " << reject << '\n';
}

int main()
try {
	const vector<string> ok_days{ "Mon", "mon", "Monday", "monday",
									"Tue", "tue", "Tues", "tues", "Tuesday", "tuesday",
									"Wed", "wed", "Wednesday", "wednesday",
									"Thur", "thur", "Thurs", "thurs", "Thursday", "thursday",
									"Fri", "fri", "Friday", "friday",
									"Sat", "sat", "Saturday", "saturday",
									"Sun", "sun", "Sunday", "sunday" };
	vector<int> mon;
	vector<int> tue;
	vector<int> wed;
	vector<int> thur;
	vector<int> fri;
	vector<int> sat;
	vector<int> sun;
	string day;
	string val;
	int reject = 0;

	while (1==1) {
		day = val = "";
		if (!get_input(day, val)) break;
		
		/*
		I assume if an illegal day is ignored, its corresponding value is ignored as well
		if want to check value regardless, check_day() and check_val() have to be on separate statements
		*/
		if (check_day(day, ok_days) && check_val(val, reject)) update_day(day, val, mon, tue, wed, thur, fri, sat, sun);
	}
	print_vals(mon, tue, wed, thur, fri, sat, sun , reject);
	
	return 0;
}
catch (runtime_error& e) {
	cerr << "Error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Error: Unkown exception'\n";
	keep_window_open();
	return 2;
}