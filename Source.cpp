/*

 *Author: Wasim Algamal

 *Creation Date: 10/05/2020

 *Modification Date: 10/07/2020

 *Purpose: Create a function that searches an array from start to finish and finds the target passed into it.
		 Then stress test that function to determine when “stack overflow” limit reached.

*/

using namespace std;
#include <iostream>

const int LENGTH = 5000;

void arrayInit(int input[], int size) {

	for (int i = 0; i < size; i++) {
		input[i] = i;
	}

}
//function to initialize array vals dependant on passed value 'size'

int recursiveLinearSearch(int array[], int key, int size, bool& methodStatus, int starter) {

	if (array[starter] == starter) {
		methodStatus = true;
		return starter;
	}
	if ((starter > size) && (starter != key)) {
		methodStatus = false;
		return 0;
	}
	else {
		int returner = recursiveLinearSearch(array, key, size, methodStatus, starter + 1);
		return returner;
	}

}
//function that recursively searches throughout the array for "starter" and returns value

int main() {
	//stack overflow warning (good sign)

	const int size = LENGTH;
	int thatOneArray[size];

	arrayInit(thatOneArray, size);

	bool methodStatus = NULL;
	int key = NULL;
	int index = NULL;
	int starter = 0;
	char sentinel = 'y';

	while (sentinel == 'y' || sentinel == 'Y') {

		while (true) {

			cout << "Enter the value you would like to search for: \n";
			cin >> key;

			if ((key >= 0) && (key < size)) {
				starter = key;
				break;
			}
			else {
				cout << "Please enter a value greater than 0 and less than " << size << endl;
			}
			//parameter check of user input value 'key' (between 'size' and 0) 

		}

		index = recursiveLinearSearch(thatOneArray, key, size, methodStatus, starter);
		//index is set to retrun value for output

		if (methodStatus == true) {
			cout << "The value was in position number " << index + 1 << "." << endl;
			cout << "The function was called " << index << " times. \n \n";
		}
		else if (methodStatus == false) {
			cout << "The number does not exist in the array.\n";
			cout << "The function was called " << index << " times. \n \n";
		}
		//results

		cout << "Enter \"y\" or \"Y\" to continue. All other input will quit the program. \n";
		cin >> sentinel;
		cout << endl;

	}
	//sentinel controlled while loop

	return 0;
}
