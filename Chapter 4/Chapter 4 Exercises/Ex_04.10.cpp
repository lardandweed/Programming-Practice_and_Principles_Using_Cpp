// play rock, paper, scissors
#include "../../../std_lib_facilities.h"

int main()
{
	vector<char> computer = { 'r', 's', 'p', 's', 'p', 'r', 'p', 'r', 's' };
	int input1 = 0;
	string input2 = "?";
	char player = '?';
	string again = "?";

	while (!cin.eof()) {
		while (1) {		// repeat request until valid input is entered
			cout << "Please enter a positive integer:\n";
			if (!(cin >> input1) || input1 < 0) {
				cout << "That is not a valid input. ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} else
				break;				
		}

		while (1) {		// repeat request until valid input is entered			
			cout << "Please enter r (rock), p (paper) or s (scissors):\n";
			cin >> input2;
			player = input2[0];
			if (player != 'r' && player != 'p' && player != 's')
				cout << "That is not a valid answer. ";
			else
				break;
		}

		switch (player) {
			case 'r':
				switch (computer[input1 % computer.size()]) {
					case 'r':
						cout << "You play rock. Computer plays rock. It's a draw!\n";
						break;
					case 'p':
						cout << "You play rock. Computer plays paper. You lose!\n";
						break;
					case 's':
						cout << "You play rock. Computer plays scissors. You win!\n";
						break;
					default:
						cout << "Something strange going on here!\n";
						break;
				}
				break;
			case 'p':
				switch (computer[input1 % computer.size()]) {
					case 'r':
						cout << "You play paper. Computer plays rock. You win!\n";
						break;
					case 'p':
						cout << "You play paper. Computer plays paper. It's a draw!\n";
						break;
					case 's':
						cout << "You play paper. Computer plays scissors. You lose!\n";
						break;
					default:
						cout << "Something strange going on here!\n";
						break;
				}
				break;
			case 's':
				switch (computer[input1 % computer.size()]) {
					case 'r':
						cout << "You play scissors. Computer plays rock. You lose!\n";
						break;
					case 'p':
						cout << "You play scissors. Computer plays paper. You win!\n";
						break;
					case 's':
						cout << "You play scissors. Computer plays scissors. It's a draw!\n";
						break;
					default:
						cout << "Something strange going on here!\n";
						break;
				}
				break;
			default:
				cout << "Soemthing strange going on here!\n";
				break;
		}

		cout << "\nEnter any key to play again (Ctrl+Z to quit)\n";
		cin >> again;
	}
}
