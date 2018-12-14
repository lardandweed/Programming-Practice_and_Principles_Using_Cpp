// find and correct errors in code 
#include "../../../std_lib_facilities.h"

/* code as shown on textbook

	double ctok(double c)			// converts Celsius to Kelvin
	{
		int k = c + 273.15;
		return int
	}

	int main()
	{
		double c = 0;				// declare input variable
		cin >> d;					// retrieve temperature to input variable
		double k = ctok("c");		// convert temperature
		Cout << k << '/n';			// print out temperature
	}

*/

/* List of errors

	1) int k = c + 273.15			// should be a double
	2) return int					// should be return k. Also no semicolon
	3) double c = 0					// should use 0.0 to indicate double value
	4) cin >> d						// c, NOT d
	5) double k = ctok("c")			// dont need ""
	6) Cout << l << '/n';			// capital C in Cout. Also '/n' should be using a backslash
	7)								// should add a return 0 in main

*/

// corrected code
double ctok(double c)			// converts Celsius to Kelvin
{
	double k = c + 273.15;
	return k;
}

int main()
{
	double c = 0.0;				// declare input variable
	cin >> c;					// retrieve temperature to input variable
	double k = ctok(c);			// convert temperature
	cout << k << '\n';			// print out temperature

	return 0;
}
