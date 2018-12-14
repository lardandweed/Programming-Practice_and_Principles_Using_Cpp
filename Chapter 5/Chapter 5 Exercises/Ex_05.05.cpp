// convert celcius to kelvin;
#include "../../../std_lib_facilities.h"

double ctok(double c)						// converts Celsius to Kelvin
{
	if (c < -273.15) error("Celcius value lower than absolute 0");	// check not lower than absolute 0
	double k = c + 273.15;
	return k;
}

double ktoc(double k)						// converts Kelvin to Celsius
{
	if (k < 0.0) error("Kelvin value lower than absolute 0"); // check not lower than absolute 0
	double c = k - 273.15;
	return c;
}

int main()
try {
	double temp = 0.0;						
	char unit = ' ';
	double conv_temp = 0.0;

	cout << "Enter temperature and unit ('k' or 'c'):\n";
	cin >> temp >> unit;					// retrieve temperature to input variables
	if (unit == 'c' || unit == 'C') {		// check unit is 'c' or 'k'
		conv_temp = ctok(temp);
		cout << temp << " Celsius == " << conv_temp << " Kelvin\n";
	} else if (unit == 'k' || unit == 'K') {
		conv_temp = ktoc(temp);
		cout << temp << " Kelvin == " << conv_temp << " Celcius\n";
	} else error("Unknown unit entered");
	
	return 0;
}
catch (runtime_error& e) {
	cerr << "Error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Unkown exception!\n";
	keep_window_open();
	return 2;
}