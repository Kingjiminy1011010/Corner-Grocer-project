#include "items.h"
#include "mainDisplay.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	items currItems;
	mainDisplay currOption;
	int displayInput;
	
	
	cout << "What would you like to do?" << endl;
	cout << "[1] : Search total count of all item" << endl;
	cout << "[2] : Print total of all items" << endl;
	cout << "[3] : Show Histogram of all items" << endl;
	cout << "[4] : Exit" << endl;

	cin >> displayInput;
	currItems.readItems();
	currItems.writeItems();

	while (displayInput != 4) {

		if (displayInput < 1 || displayInput > 4) {
			cout << "Error: Enter 1-4" << endl;
			cin >> displayInput;

		}

		if (displayInput == 1) {
			currOption.getUserInput();
			cout << endl;
			break;
		
		}

		if (displayInput == 2) {
			currItems.printAllTotal();
			break;
			
		}

		if (displayInput == 3) {
			currItems.mapDisplay();
			cin >> displayInput;
			break;
		}

		if (displayInput == 4) {

				cout << "Goodbye :)" << endl;
		}
	}
	
	


}