
#ifndef Items_H
#define Items_H

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

// declare  
class items {
public:
	void readItems();
	map<string, int> mapOfItems;
	void addItem(string);
	int getItemFrequency(string);
	void mapDisplay();
	void printAllTotal();
	void writeItems();
	


private:
	ifstream readItemsInFS;
	ofstream writeItemsOutFS;
	string inputItem;
	int i;
};
#endif
