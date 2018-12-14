// convert celcius to kelvin; add check in ctok()
#include "../../../std_lib_facilities.h"

double ctok(double c)			// converts Celsius to Kelvin
{
	if (c < -273.15) error("celcius value lower than absolute 0");	//check value of c
	
	double k = c + 273.15;
	return k;
}

int main()
try {
	double c = 0.0;				// declare input variable
	cin >> c;					// retrieve temperature to input variable
	double k = ctok(c);			// convert temperature
	cout << k << '\n';			// print out temperature

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