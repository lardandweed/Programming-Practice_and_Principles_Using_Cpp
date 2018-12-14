// find roots of a quadratic equation
/*
A quadratic equation ax^2 + bx + c = 0 has roots:
	x1 = [(-b + sqrt(b^2 - 4ac)) / 2a]
	x2 = [(-b - sqrt(b^2 - 4ac)) / 2a]

If the discriminant (b^2 - 4ac) > 0, equation has two distinct roots
If the discriminant (b^2 - 4ac) = 0, equation has two equal roots
If the discriminant (b^2 - 4ac) < 0, equation has no real roots
*/
#include "../../../std_lib_facilities.h"

// calculate discriminant
double discriminant(double a, double b, double c)
{
	double d;		// declare discriminant
	
	if ((pow(b, 2) - (4 * a * c)) < 0)
		error("Equation has no real roots");
	else
		d = pow(b, 2) - (4 * a * c);
	return d;
}

// checks validity of root values; result must be <= limit
void check_root(double root, double a, double b, double c) 
/*
Sub root into equation to check
If indeed a root, then a(root)^2 + b(root) + c = 0
Due to rounding errors, adopt a maximum threshold:
	a(root)^2 + b(root) + c <= limit
*/
{
	const double limit = 0.0001;		// declare maximum threshold

	double result = (a * pow(root, 2)) + (b * root) + c;
	if (result > limit) error("Roots do not satisfy equation");
	return;
}

int main()
try {
	double a;			// declare coefficient of x^2
	double b;			// declare coefficient of x 
	double c;			// declare constant term
	double x1;			// declare first root of equation
	double x2;			// declare second root of equation

	// retrieve values for coefficients of equation
	// if a == 0, equation is no longer quadratic
	cout << "A quadratic equation has the form ax^2 + bx + c = 0\n"
		<< "Enter values for a, b, and c (a must not be 0):\n";
	cin >> a >> b >> c;
	if (!cin || a == 0) error("Illegal inputs");

	// calculate roots of the equation
	x1 = (-b + sqrt(discriminant(a, b, c))) / (2 * a);
	x2 = (-b - sqrt(discriminant(a, b, c))) / (2 * a);

	// post-conditions: check validity of results:
	check_root(x1, a, b, c);
	check_root(x2, a, b, c);
	cout << "The equation has roots x1 == " << x1 << " and x2 == " << x2 << '\n';

	return 0;
}
catch (runtime_error& e) {
	cerr << "Error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Error: Unknown exception\n";
	keep_window_open();
	return 2;
}