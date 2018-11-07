// convert digits to spelled out numbers and vice versa
#include "../../../std_lib_facilities.h"

void convert(string strToConvert, string numSpellForm, string numDigitForm);

int main()
{
	vector<string> spelledNum = { "zero", "one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine" };
	vector<string> digit = { "0", "1", "2", "3", "4", "5",
		"6", "7", "8", "9" };
	string input = "?";
	bool okInput = false;

	// check validity of user input
	while (okInput == false) {
		cout << "Enter a digit (in spelled or numerical form):\n";
		cin >> input;
		for (int i = 0; i < 10; ++i)
			if (input == spelledNum[i] || input == digit[i]) {
				// input is valid >>> convert and print
				convert(input, spelledNum[i], digit[i]);
				okInput = true;
				break;
			}
		if (okInput == true)
			break;
		else
			cout << "That is not a valid input. ";
	}
}

void convert(string input, string spellForm, string digitForm)
{
	if (input == spellForm)
		cout << input << " in digit form is " << digitForm << ".\n";
	else
		cout << input << " spelled out is " << spellForm << ".\n";
}