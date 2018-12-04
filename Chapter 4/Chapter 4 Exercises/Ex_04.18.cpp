// Find roots of a quadratic equation
#include "../../../std_lib_facilities.h"

int main()
{
	double aVal;
	double bVal;
	double cVal;

	cout << "A quadratic equation has the form ax^2 + bx + c = 0\n";
	cout << "Enter values for a, b, and c separated by a space:\n";
	cin >> aVal >> bVal >> cVal;

	/*
	the roots for a quadratic equation ax^2 + bx + c = 0 are given by the formula x = [-b (+-) sqrt(b^2 - 4ac)] / 2a
	if the discriminant (b^2 - 4ac) < 0, the equation has no real roots
	if the discriminant == 0, the equation has duplicate roots
	if the discriminant > 0, the equation has two distinct roots
	*/

	double discriminant = pow(bVal, 2) - (4 * aVal * cVal);
	if (discriminant < 0)
		cout << "Equation has no real roots.\n";
	else if (discriminant == 0)
		cout << "Equation has duplicate roots x1 = x2 = " << -bVal / (2 * aVal);
	else
		cout << "First root of the equation x1 = " << (-bVal + sqrt(discriminant)) / (2 * aVal) << "\n"
		<< "Second root of the equation x2 = " << (-bVal - sqrt(discriminant)) / (2 * aVal) << "\n";
}