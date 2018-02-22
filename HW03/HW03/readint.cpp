#include "readint.h"
#include <stdexcept>
#include <iostream>
#include <limits>
#include<ios>
using namespace std;

int read_int(const string &prompt, int low, int high)
{

	if (low >= high) {
		throw std::invalid_argument("That is not a valid range");
	}
	cin.exceptions(ios_base::failbit);
	int number = 0;
	bool flag = false;
	while (flag == false) {
		try {
			cout << prompt;
			cin >> number;
			if (number > low && number < high) {
				flag = true;
			}
			else if (number <= low || number >= high) {
				throw std::range_error("the number you entered was not in the range");
			}
		}
		catch (ios_base::failure& ex) {
			cout << "You did not enter an integer\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (range_error) {
			cout << "the number you entered was not in the range\n";
			cin.clear();
		}

	}

	return number;

}