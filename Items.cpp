#include "items.h"
#include <iostream>
#include <fstream>
using namespace std;

// back-up items
void items::writeItems() {
	cout << "Writing frequency.dat" << endl;
	writeItemsOutFS.open("frequency.dat");

	if (!writeItemsOutFS.is_open()){
		cout << "Could not open file frequency.dat." << endl;
		return;
	}

	for (map<string, int>::const_iterator iter = mapOfItems.begin(); iter != mapOfItems.end(); iter++) {
		writeItemsOutFS << iter->first << " " << iter->second << endl;
		
	}

	cout << "Closing frequency.dat" << endl;
	writeItemsOutFS.close();
}

// reads items
void items::readItems() {

	cout << "Opening CS210_Project_Three_Input_File.txt" << endl;	
	readItemsInFS.open("CS210_Project_Three_Input_File.txt");
	
	if (!readItemsInFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
		return;
		
	}
	
	cout << "Reading Items..." << endl;
	readItemsInFS >> inputItem;
	
	while (!readItemsInFS.fail()) {
		readItemsInFS >> inputItem;
		addItem(inputItem);
		cout << inputItem << endl;
	}
	
	if (!readItemsInFS.eof()) {
		cout << "Input failure before reaching end of file." << endl;
	}
	
	cout << "Closing file CS210_Project_Three_Input_File.txt." << endl;
	readItemsInFS.close();
}

// adds items with same name
void items::addItem(string item) {
	mapOfItems[item]++;
}

// gets total of item
int items::getItemFrequency(string item) {
	return mapOfItems[item];
}
// creates histogram of items
void items::mapDisplay() {
	readItems();
	cout << endl;
	for (auto& entry : mapOfItems)
		cout << entry.first << " " << string(entry.second, '*') << endl;
	cout << endl;
}

// prints all items with total of each item
void items::printAllTotal() {
	readItems();
	cout << endl;
	for (auto& entry : mapOfItems)
		cout << entry.first << " " << int(entry.second) << endl;
	cout << endl;
}