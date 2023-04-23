#include "mainDisplay.h"
#include "items.h"
#include <iostream>
using namespace std;

void mainDisplay::getUserInput() {

	cout << "What item would you like to look-up?" << endl;
	cin >> userInput;
	searchWord.readItems();
	cout << searchWord.getItemFrequency(userInput);
}

