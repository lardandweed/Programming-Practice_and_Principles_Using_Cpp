/*
Write a program that checks if a sentence is correct according to the “En-
glish” grammar in §6.4.1. Assume that every sentence is terminated by
a full stop (.) surrounded by whitespace. 

For example, "birds fly but the fish swim ." is a sentence, 
but "birds fly but the fish swim" (terminating dot missing) 
and "birds fly but the fish swim." (no space before dot) are not. 

For each sentence entered, the program should simply respond “OK” or “not
OK.” Hint: Don’t bother with tokens; just read into a string using >> .
*/

/*
I still can't figure out to method (without using getline) to make 
the program determine that a sentence without a fullstop at the end is not ok.

	e.g: "birds fly but the fish swim" (terminating dot missing)

This is because the sentence can be infinitely recursive.
i.e. sentence + (conjunction + sentence) + (conjunction + sentence) + ...

At the end of a legal sentence, cin will always be waiting for the next input 
(fullstop or conjunction) and cannot tell that the line has ended.
*/

#include "../../../std_lib_facilities.h"

vector<string> noun{ "birds", "fish", "C++" };
vector<string> verb{ "fly", "swim", "rules" };
vector<string> conj{ "and", "or", "but" };

bool is_sentence();

// check for legal nouns and noun phrases ('the' + noun)
bool is_noun()
{
	string word;

	cin >> word;
	if (word == "the") cin >> word;
	for (string entry : noun)
		if (word == entry) return true;
	return false;
}

// check for legal verbs
bool is_verb()
{
	string word;

	cin >> word;
	for (string entry : verb)
		if (word == entry) return true;
	return false;
}

// check for fullstop or (conjunction + sentence)
bool is_conj()
{
	string word;

	cin >> word;
	if (word == ".") 
		return true;
	for (string entry : conj)
		if (word == entry)
			return is_sentence();
		
	return false;
}

//check for a legal sentence.
/* 
	a legal sentence has either of the following forms:
		1) noun phrase + verb + fullstop
		2) noun phrase + verb + conjunction + sentence
*/
bool is_sentence()
{
	if (!is_noun()) return false;
	if (!is_verb()) return false;
	if (!is_conj()) return false;

	return true;
}

int main()
try {
	bool ok;
	
	while (cin) {
		cout << "Enter a sentence (ctrl+z to quit):\n";
		ok = is_sentence();
		
		// allow users to quit by entering ctrl+z
		if (cin.eof()) {
			cout << "Exit program\n";
			break;
		}

		if (ok)
			cout << "OK\n";
		else
			cout << "not OK\n";

		/*
		ignores all input after fullstop or erroneous part of sentence
		allows next sentence to start "fresh"

		For example: "the birds the fish swim ."

		At the 2nd 'the', sentence is not ok because a verb is expected after noun phrase 'the birds'.
		The remaining input 'fish swim .' is discarded instead of 
		being thrown into the next loop to be parsed
		*/
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return 0;
}
catch (runtime_error& e) {
	cerr << "Error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Error: Unknown error\n";
	keep_window_open();
	return 2;
}