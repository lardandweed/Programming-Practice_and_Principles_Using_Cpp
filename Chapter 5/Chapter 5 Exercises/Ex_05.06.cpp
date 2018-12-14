// convert Celsius to Fahrenheit and vice versa
// formula: (0°C × 9/5) + 32 = 32°F
#include "../../../std_lib_facilities.h"

double ctof(double c)		// converts Celcius to Fahrenheit
{
	// precondition: c must be >= -273.15
	if (c < -273.15) error("Celcius value less than absolute zero");
	
	double f = (c * 9.0 / 5.0) + 32.0;
	return f;
}

double ftoc(double f)		// converts Fahrenheit to Celsius
{
	// precondition: f must be >= -459.67
	if (f < -459.67) error("Fahrentheit value less than absolute zero");

	double c = (f - 32.0) * 5 / 9;
	return c;
}

int main()
try {
	double temp;			// temperature to be converted
	char unit;				// unit to be converted
	double conv_temp;		// converted temperature

	cout << "Enter temperature and unit ('c' or 'f') to be converted:\n";
	cin >> temp >> unit;

	if (!cin) error("Illegal inputs");
	//check ctof or ftoc conversion depending on unit entered
	if (unit == 'c' || unit == 'C') {		
		conv_temp = ctof(temp);
		cout << temp << " Celcius == " << conv_temp << " Fahrenheit\n";
	} else if (unit == 'f' || unit == 'F') {
		conv_temp = ftoc(temp);
		cout << temp << " Fahrenheit == " << conv_temp << " Celcius\n";
	} else error("Unknown unit entered\n");
	
	keep_window_open();
	return 0;
}
catch (runtime_error& e) {
	cerr << "Error:	" << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Error: Unknown exception\n";
	keep_window_open();
	return 2;
}